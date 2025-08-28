#include <iostream>
#include <cmath>
#include <fstream>
#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called\n";
	_value = roundf(n * (1 << _fract_bits));
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called\n";
	_value = n << _fract_bits;
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout << "Copy constructor called\n";
	_value = src.getRawBits();
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	//std::cout << "Copy assignment operator called\n";
	if (this != &src)
		_value = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& src) const
{
	return (_value > src._value);
}

bool	Fixed::operator<(const Fixed& src) const
{
	return (_value < src._value);
}


bool	Fixed::operator>=(const Fixed& src) const
{
	return (_value >= src._value);
}

bool	Fixed::operator<=(const Fixed& src) const
{
	return (_value <= src._value);
}

bool	Fixed::operator==(const Fixed& src) const
{
	return (_value == src._value);
}

bool	Fixed::operator!=(const Fixed& src) const
{
	return (_value != src._value);
}

Fixed	Fixed::operator+(const Fixed& src) const
{
	Fixed	result;

	result.setRawBits(_value + src._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& src) const
{
	Fixed	result;

	result.setRawBits(_value - src._value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& src) const
{
	Fixed		result;
	long long	tmp;

	tmp = (long long)_value * (long long)src._value >> _fract_bits;
	result.setRawBits(tmp);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& src) const
{
	Fixed		result;
	long long	tmp;

	tmp = ((long long)_value << _fract_bits) / src._value;
	result.setRawBits(tmp);
	return (result);
}

Fixed	Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	_value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return ((a > b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return ((a > b) ? a : b);
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
