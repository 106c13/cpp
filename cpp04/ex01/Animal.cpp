#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& src) : type(src.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal&	Animal::operator=(const Animal& src)
{
	std::cout << "Animal copy operator called\n";
	if (this != &src)
		type = src.type; 
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal: I can't make sound\n";
}

std::string	Animal::getType() const
{
	return (type);
}
