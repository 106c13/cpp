#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(const Point& point) : _x(point.getX()), _y(point.getY())
{
}

Point&	Point::operator=(const Point& point)
{
	if (this != &point)
	{
		_x = point._x;
		_y = point._y;
	}
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
