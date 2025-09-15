#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    {
        std::vector<int>    v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        try
        {
            std::vector<int>::iterator it = easyfind(v, 20);
            std::cout << "Found: " << *it << std::endl;
            it = easyfind(v, 99);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::vector<int>    v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        try
        {
            std::vector<int>::iterator it = easyfind(v, 0);
            std::cout << "Found: " << *it << std::endl;
            it = easyfind(v, 99);
            std::cout << "Found: " << *it << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

