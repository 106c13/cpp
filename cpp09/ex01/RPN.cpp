#include <iostream>
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) {
	(void)src;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& src) {
	if (this != &src)
		*this = src;
	return *this;
}

int	RPN::exec_(char op) {
	int	a;
	int b;

	a = numbers_.top();
	numbers_.pop();
	b = numbers_.top();
	numbers_.pop();
	if (op == '+')
		return b + a;
	if (op == '-')
		return b - a;
	if (op == '*')
		return b * a;
	return b / a;
}

void	RPN::calculate(const std::string& input) {
	std::string	nums = "0123456789";
	std::string	ops = "+-/*";
	int			numsCount = 0;
	int			number;

	for (size_t i = 0; i < input.size(); i++) {
		if (nums.find(input[i]) != std::string::npos) {
			numsCount++;
			number = input[i] - '0';
			numbers_.push(number);
		} else if (ops.find(input[i]) != std::string::npos) {
			if (numbers_.size() < 2) {
				std::cout << "Error\n";
				return;
			}
			numbers_.push(exec_(input[i]));
		}
		else if (input[i] != ' ') {
			std::cout << "Error\n";
			return;
		}
	}
	if (numbers_.size() != 1) {
		std::cout << "Error\n";
		return;
	}
	std::cout << numbers_.top() << std::endl;
}

