#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>


class	RPN
{
private:
	std::stack<int>numbers_;

	int	exec_(char op);
public:
	RPN();
	RPN(const RPN& src);
	~RPN();

	RPN&	operator=(const RPN& src);

	void	calculate(const std::string& input);
};

#endif
