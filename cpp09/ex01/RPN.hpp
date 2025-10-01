#ifndef RPN_HPP
#define RPN_HPP

#include <stack>


class	RPN
{
private:
	stack<int>	numbers_;
	stack<char>	operators_;
public:
	RPN();
	RPN(const RPN src);
	~RPN();

	RPN	operator=(const RPN src);

	void	
}
