#include <iostream>
#include "Span.hpp"

int main()
{
	std::cout << "1 ==========================================\n";
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "2 ==========================================\n";

	try {
		Span sp(4);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.addNumber(1);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "3 ==========================================\n";
	try {
		Span sp(4);
        std::cout  << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
    return 0;
}

