#include <iostream>
#include <string>
#include "RPN.hpp"

int	main(int argc, char** argv)
{
	RPN	rpn;
	if (argc != 2) {
		std::cout << "Error\n";
		return 1;
	}
	rpn.calculate(argv[1]);
	return 0;
}
