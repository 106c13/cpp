#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "🐱 Cat default constructor called\n";
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "🐱 Cat copy constructor called\n";
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "🐱 Cat copy operator called\n";
	if (this != &src)
		type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "🐱 Cat destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "🐱 Cat: meow\n";
}
