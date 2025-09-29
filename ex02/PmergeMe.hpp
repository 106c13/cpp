#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <exception>
#include <string>

class PmergeMe {
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
	PmergeMe(char **argv);
	~PmergeMe();

    PmergeMe& operator=(const PmergeMe& src);

    void		sort(std::vector<int>& arr);
    void		sort(std::deque<int>& arr);
	std::string	getVectorArray() const;
	std::string	getDequeArray() const;
	
	class	IsNotNumberException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
	class	OutOfRangeException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

#endif
