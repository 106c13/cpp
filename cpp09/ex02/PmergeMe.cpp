#include <string>
#include <sstream>
#include <limits.h>
#include <cstdlib>
#include "PmergeMe.hpp"

size_t	skipDigit(const std::string& literal, size_t i)
{
	for (; i < literal.size(); i++)
	{
		if (!isdigit(literal[i]))
			return std::string::npos;
	}
	return i; 
}

static bool	isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (literal[i] == '\0')
		return false;
	i = skipDigit(literal, i);
	return i != std::string::npos;
}

/* Contructors */
PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	_vec = src._vec;
	_deq = src._deq;
}

PmergeMe::PmergeMe(char **argv) {
	std::string	s;
	long		num;

	for (int i = 1; argv[i]; i++) {
		s = argv[i];

		if (!isInt(s))
            throw IsNotNumberException();
		num = strtol(argv[i], NULL, 10);
        if (num <= 0 || num > INT_MAX)
        	throw OutOfRangeException();

        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }
}

PmergeMe::~PmergeMe()
{
}

/* Operators */
PmergeMe&	PmergeMe::operator=(const PmergeMe& src)
{
	if (this == &src)
		return *this;
	_vec = src._vec;
	_deq = src._deq;
	return *this;
}

/* Methods */
std::string	PmergeMe::getVectorArray() const {
	std::ostringstream	oss;

	for (long unsigned i = 0; i < _vec.size(); i++)
	{
		oss << _vec[i];
		if (i + 1 < _vec.size())
			oss << " ";
	}
	return oss.str();
}

std::string	PmergeMe::getDequeArray() const {
	std::ostringstream	oss;

	for (long unsigned i = 0; i < _deq.size(); i++)
	{
		oss << _deq[i];
		if (i + 1 < _deq.size())
			oss << " ";
	}
	return oss.str();
}

void	PmergeMe::sort()
{

}

const char*	PmergeMe::IsNotNumberException::what() const throw()
{
	return ("Argument is not a number");
}

const char*	PmergeMe::OutOfRangeException::what() const throw()
{
	return ("Argument must be from 0 to INT_MAX");
}
