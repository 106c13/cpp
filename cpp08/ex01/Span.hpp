#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
private:
	unsigned int		size_;
	std::vector<int>	data_;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& src);
	~Span();

	Span&	operator=(const Span& src);

	void			addNumber(int num);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	class	SpanOverflowException : public std::exception
	{
		public: const char*	what() const throw();
	};

	class	NotEnoughElementsException : public std::exception
	{
		public: const char*	what() const throw();
	};
};

#endif
