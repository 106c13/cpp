#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    Array<int> c(b);
    std::cout << "c (copy of b):" << std::endl;
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << "c[" << i << "] = " << c[i] << std::endl;

    c[0] = 999;
    std::cout << "c[0] = " << c[0] << ", b[0] = " << b[0] << std::endl;

    Array<int> d;
    d = c;
    std::cout << "d (assigned from c):" << std::endl;
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << "d[" << i << "] = " << d[i] << std::endl;

    try {
        std::cout << b[10] << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

