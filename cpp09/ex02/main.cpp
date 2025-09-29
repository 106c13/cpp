#include <iostream>
#include <string>
#include <exception>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc > 1)
    {
        try {
            PmergeMe sorter(argv);
            //sorter.sort();
            std::cout << "Before: " << sorter.getVectorArray() << std::endl;
            std::cout << "Before: " << sorter.getVectorArray() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    } else {
        std::cout << "Not enought argument\n";
        return 1;
    }
    return 0;
}
