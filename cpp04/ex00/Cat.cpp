#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "🐱 Cat default constructor called\n";
}

Cat::Cat(const Cat& src) : Animal()
{
	std::cout << "🐱 Cat copy constructor called\n";
	if (this == &src)
		return ;
	type = src.type;
}

Cat	Cat::operator=(const Cat& src)
{
	std::cout << "🐱 Cat copy operator called\n";
	if (this != &src)
		type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "🐱 Cat desctructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "🐱 Cat: meow\n";
}
