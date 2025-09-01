#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "🐶 Dog default constructor called\n";
}

Dog::Dog(const Dog& src) : Animal()
{
	std::cout << "🐶 Dog copy constructor called\n";
	if (this == &src)
		return ;
	Animal();
	type = src.type;
}

Dog	Dog::operator=(const Dog& src)
{
	std::cout << "🐶 Dog copy operator called\n";
	if (this != &src)
		type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "🐶 Dog desctructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "🐶 Dog: bark\n";
}
