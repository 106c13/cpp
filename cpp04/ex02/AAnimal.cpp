#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal& src) : type(src.type)
{
	std::cout << "Animal copy constructor called\n";
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called\n";
}

AAnimal&	AAnimal::operator=(const AAnimal& src)
{
	std::cout << "Animal copy operator called\n";
	if (this != &src)
		type = src.type; 
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "Animal: I can't make sound\n";
}

std::string	AAnimal::getType() const
{
	return (type);
}
