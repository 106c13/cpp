#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error: usage: ./PmergeMe [positive integers...]" << std::endl;
		return 1;
	}

	try {
		PmergeMe sorter(argv);
		sorter.printBefore();
		sorter.sortAndMeasure();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
