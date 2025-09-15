#include <vector>
#include <algorithm>
#include <exception>
#include <limits.h>
#include "Span.hpp"

Span::Span() :
	size_(0)
{
}

Span::Span(unsigned int n) :
	size_(n)
{
}

Span::Span(const Span& src) :
	size_(src.size_),
	data_(src.data_)
{
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& src)
{
	if (this != &src)
	{
		size_ = src.size_;
		data_ = src.data_;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (data_.size() == size_)
		throw SpanOverflowException();
	data_.push_back(num);
}

unsigned int	Span::shortestSpan() const
{
	if (data_.size() < 2)
		throw NotEnoughElementsException();	

	std::vector<int>	tmp = data_;
	unsigned int		min_span = UINT_MAX;
	unsigned int		span;

	std::sort(tmp.begin(), tmp.end());
	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		span = tmp[i + 1] - tmp[i];
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

unsigned int	Span::longestSpan() const
{
	if (data_.size() < 2)
		throw NotEnoughElementsException();

	int				minVal = *std::min_element(data_.begin(), data_.end());
	int				maxVal = *std::max_element(data_.begin(), data_.end());
	unsigned int	span = maxVal - minVal;
	
	return span;
}

const char*	Span::SpanOverflowException::what() const throw()
{
	return "Span overflow!!!";
}

const char*	Span::NotEnoughElementsException::what() const throw()
{
	return "Span has less then 2 element";
}
