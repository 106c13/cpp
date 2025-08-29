#include <iostream>
#include <string>
#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& src)
{
	std::cout << "Dog copy constructor called\n";
	if (this == &src)
		return ;
	_type = src._type;
}

Dog	Dog::operator=(const Dog& src)
{
	std::cout << "Dog copy operator called\n";
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);

Dog::~Dog()
{
	std::cout << "Dog desctructor called\n";
}

void	Dog::makeSound()
{
	std::cout << "Dog: bark\n";
}
