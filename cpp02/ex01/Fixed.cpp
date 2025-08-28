#include <iostream>
#include <cmath>
#include <fstream>
#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	_value = roundf(n * (1 << _fract_bits));
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	_value = n << _fract_bits;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called\n";
	_value = src.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		_value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fract_bits));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fract_bits);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
	_value = raw;
}

std::ostream&	operator<<(std::ostream &o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
}
