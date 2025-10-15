#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <ctime>
# include <stdexcept>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <climits>
# include <cstdlib>
# include <cctype>

class PmergeMe {
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	template <typename Container>
	void	mergeInsertSort(Container& cont);

	template <typename Container>
	void	createPairs(Container& cont, Container& pend);

	template <typename Container>
	void	insertPendElements(Container& mainChain, Container& pend);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	~PmergeMe();

	PmergeMe(char **argv);

	void	sortAndMeasure();
	void	printBefore() const;
	void	printAfter() const;

	class InvalidInputException : public std::exception {
		public: const char* what() const throw();
	};
	class OutOfRangeException : public std::exception {
		public: const char* what() const throw();
	};
};

#endif
