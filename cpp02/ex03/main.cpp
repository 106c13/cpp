#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main( void )
{
	Point	a(0, 0);
	Point	b(1, 2);
	Point	c(3, 0);
	Point	p(2.5, 1);

	if (bsp(a, b, c, p))
		std::cout << "YESSSS" << std::endl;
	else
		std::cout << "NOOOOO" << std::endl;
	return 0;
}
