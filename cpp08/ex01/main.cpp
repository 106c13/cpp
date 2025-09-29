#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	std::cout << "1 ==========================================\n";
    try {
        std::vector<int>	arr;
		Span				sp(5);

		arr.push_back(6);
		arr.push_back(3);
		arr.push_back(17);
		arr.push_back(9);
		arr.push_back(11);

        sp.addNumbers(arr.begin(), arr.end());

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
	std::cout << "4 ==========================================\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
    return 0;
}

