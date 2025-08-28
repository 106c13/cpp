#include "Fixed.hpp"
#include "Point.hpp"

Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
			- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	d1 = sign(p, a, b);
    Fixed	d2 = sign(p, b, c);
    Fixed	d3 = sign(p, c, a);
    bool	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return (!(has_neg && has_pos) && d1 != 0 && d2 != 0 && d3 != 0);
}
