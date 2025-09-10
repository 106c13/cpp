#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"
#include "Base.hpp"

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base* obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
    }

    return 0;
}

