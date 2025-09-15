#include <iostream>
#include "template.hpp"

int main()
{
    {
        int x = 10;
        int y = 22;

        std::cout << "X: " << x << "  " << "Y: " << y << std::endl;
        swap(x, y);
        std::cout << "X: " << x << "  " << "Y: " << y << std::endl;
    }
    std::cout << std::endl;
    {
        char x = 'a';
        char y = 'b';
        char z = min(x,y);

        std::cout << "X: " << x << "  " << "Y: " << y  << "   Z: " << z << std::endl;
    }
    std::cout << std::endl;
    {
        const long x = 10;
        const long y = 22;
        int z = max(x,y);

        std::cout << "X: " << x << "  " << "Y: " << y  << "   Z: " << z << std::endl;
    }
    std::cout << std::endl;
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return (0);
}
