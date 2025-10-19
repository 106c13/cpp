#include "PmergeMe.hpp"

#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <ctime>

/* -------------------------
   Helpers & validation
   ------------------------- */

static bool isInt(const std::string& s)
{
	if (s.empty()) return false;
	for (size_t i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

/* ---------- Constructors ---------- */

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }
PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	if (this != &src) {
		_vec = src._vec;
		_deq = src._deq;
	}
	return *this;
}

PmergeMe::PmergeMe(char **argv)
{
	std::string s;
	long num;

	for (int i = 1; argv[i]; ++i)
	{
		s = argv[i];
		if (!isInt(s))
			throw InvalidInputException();
		num = std::atol(s.c_str());
		if (num <= 0 || num > INT_MAX)
			throw OutOfRangeException();
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
}

/* ---------- Exceptions ---------- */

const char* PmergeMe::InvalidInputException::what() const throw() {
	return "Error: invalid input";
}
const char* PmergeMe::OutOfRangeException::what() const throw() {
	return "Error: out of range";
}

/* -------------------------
   Pair comparator functor
   (no lambdas; C++98)
   ------------------------- */

template <typename Pair>
struct PairSecondLess {
	bool operator()(const Pair& a, const Pair& b) const {
		return a.second < b.second;
	}
};

/* -------------------------
   mergeInsertSort template
   works for std::vector<int> and std::deque<int>
   ------------------------- */

template <typename Container>
void PmergeMe::mergeInsertSort(Container& cont)
{
	typedef typename Container::value_type T;

	if (cont.size() <= 1)
		return;

	// 1) Create pairs and possibly a leftover
	std::vector< std::pair<T, T> > pairs;
	Container pend; // will store the smaller elements in pair order
	bool hasLeftover = false;
	T leftover = 0;

	typename Container::iterator it = cont.begin();
	while (it != cont.end())
	{
		T a = *it;
		++it;
		if (it != cont.end()) {
			T b = *it;
			++it;
			if (a > b) std::swap(a, b);
			pairs.push_back(std::make_pair(a, b));
		} else {
			// leftover single element
			hasLeftover = true;
			leftover = a;
		}
	}

	// 2) Sort pairs by their second element (the "larger" value)
	std::sort(pairs.begin(), pairs.end(), PairSecondLess< std::pair<T,T> >());

	// 3) Build mainChain from seconds and pend from firsts
	Container mainChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	// place the very first smallest 'first' at the front of mainChain
	if (!pairs.empty()) {
		// insert at begin works for both vector and deque
		mainChain.insert(mainChain.begin(), pairs[0].first);
		pend.erase(pend.begin());
	}

	// 4) Jacobsthal sequence (array literal, C++98)
	static const size_t jacob[] = {
		1u, 3u, 5u, 11u, 21u, 43u, 85u, 171u,
		341u, 683u, 1365u, 2731u, 5461u, 10923u, 21845u, 43691u
	};
	const size_t jacobCount = sizeof(jacob) / sizeof(jacob[0]);

	// Build the insertion order indices (0-based) using Jacobsthal
	std::vector<size_t> insert_indices;
	size_t prev_j = 0;
	for (size_t k = 1; k < jacobCount && jacob[k] <= pend.size(); ++k) {
		size_t cur = jacob[k];
		// push indices cur-1 down to prev_j (exclusive)
		for (size_t j = cur; j > prev_j; --j) {
			insert_indices.push_back(j - 1);
		}
		prev_j = cur;
	}
	// Remaining pend elements after last jacob
	for (size_t j = pend.size(); j > prev_j; --j) {
		insert_indices.push_back(j - 1);
	}

	// 5) Insert pend elements into mainChain following insert_indices order
	for (size_t idx = 0; idx < insert_indices.size(); ++idx) {
		size_t pidx = insert_indices[idx];
		// guard (shouldn't happen)
		if (pidx >= pend.size()) continue;
		T val = pend[pidx];
		typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(pos, val);
	}

	// 6) Insert leftover if present
	if (hasLeftover) {
		typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	// 7) assign sorted result back to original container
	cont.assign(mainChain.begin(), mainChain.end());
}

/* explicit instantiation declarations (optional) */
template void PmergeMe::mergeInsertSort< std::vector<int> >(std::vector<int>&);
template void PmergeMe::mergeInsertSort< std::deque<int> >(std::deque<int>&);

/* -------------------------
   Public interface: printing & timing
   ------------------------- */

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	if (_vec.size() == 0)
		std::cout << "Empty";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
		if (i == 4)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	if (_vec.size() == 0)
		std::cout << "Empty";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
		if (i == 4)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::sortAndMeasure()
{
	clock_t s1 = clock();
	mergeInsertSort(_vec);
	clock_t e1 = clock();

	clock_t s2 = clock();
	mergeInsertSort(_deq);
	clock_t e2 = clock();

	printAfter();

	double tvec = double(e1 - s1) / CLOCKS_PER_SEC * 1000000.0;
	double tdeq = double(e2 - s2) / CLOCKS_PER_SEC * 1000000.0;

	if (_vec.size() != 0) {
		std::cout << "Time to process a range of " << _vec.size()
				  << " elements with std::vector : " << tvec << " us" << std::endl;
		std::cout << "Time to process a range of " << _deq.size()
				  << " elements with std::deque  : " << tdeq << " us" << std::endl;
	}
}
