#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed	_x;
	Fixed	_y;
public:
	Point();
	Point(float x, float y);
	Point(const Point& point);
	Point&	operator=(const Point& point);
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
	bool	bsp(Point const a, Point const b, Point const c, Point const point);
};
#endif
