#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	type = "Dog";
	_brain = new Brain();
	std::cout << "🐶 Dog default constructor called\n";
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "🐶 Dog copy constructor called\n";
	_brain = new Brain(*src._brain);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "🐶 Dog destructor called\n";
}

Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "🐶 Dog copy operator called\n";
	if (this != &src)
	{
		type = src.type;
		Brain* tmp = new Brain(*src._brain);
		delete _brain;
		_brain = tmp; 
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "🐶 Dog: bark\n";
}

void	Dog::setBrainIdea(int i, const std::string& str)
{
	_brain->setIdea(i, str);
}

std::string	Dog::getBrainIdea(int i) const
{
	return (_brain->getIdea(i));
}
