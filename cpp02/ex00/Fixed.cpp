#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fided& src)
{
	_value = src.getRawBits();
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed& src)
{
	_value = src.getRawBits();
	std::cout << "Copy constructor called\n";
}

void	Fixed::getRawBits(void)
{
	return (_
