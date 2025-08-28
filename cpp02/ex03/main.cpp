#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main( void )
{
	Point	a(-10, 0);
	Point	b(0, 10);
	Point	c(10, 0);
	Point	p1(2.5, 1);
	Point	p2(20.5, 1);
	Point	p3(-10, 0.1);

	if (bsp(a, b, c, p1))
		std::cout << "P1 YES" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "P2 YES" << std::endl;
	if (bsp(a, b, c, p3))
		std::cout << "P3 YES" << std::endl;
	return 0;
}
