#include <cstdlib>
#include <exception>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

Base* generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    } catch (std::exception &e) {
		//std::cout << e.what() << std::endl;
	}
    
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    } catch (std::exception &e) {
		//std::cout << e.what() << std::endl;
	}
    
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    } catch (std::exception &e) {
		//std::cout << e.what() << std::endl;
	}

    std::cout << "Unknown" << std::endl;
}

