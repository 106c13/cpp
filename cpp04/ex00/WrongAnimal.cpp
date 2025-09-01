#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "WrongAnimal copy constructor called\n";
	type = src.type; 
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "WrongAnimal copy operator called\n";
	if (this != &src)
		type = src.type; 
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal making sound\n";
}

std::string	WrongAnimal::getType() const
{
	return (type);
}
