#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called\n";
	type = src.type; 
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal	Animal::operator=(const Animal& src)
{
	std::cout << "Animal copy operator called\n";
	if (this != &src)
		type = src.type; 
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "NOTHING";
}

std::string	Animal::getType() const
{
	return (type);
}
