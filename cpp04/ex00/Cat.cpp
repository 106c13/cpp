#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat() : _type("Cat")
{
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& src)
{
	std::cout << "Cat copy constructor called\n";
	if (this == &src)
		return ;
	_type = src._type;
}

Cat	Cat::operator=(const Cat& src)
{
	std::cout << "Cat copy operator called\n";
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);

Cat::~Cat()
{
	std::cout << "Cat desctructor called\n";
}

void	Cat::makeSound()
{
	std::cout << "Cat: meow\n";
}
