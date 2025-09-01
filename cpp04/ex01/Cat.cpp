#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	type = "Cat";
	_brain = new Brain();
	std::cout << "🐱 Cat default constructor called\n";
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "🐱 Cat copy constructor called\n";
	_brain = new Brain(*src._brain); 
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "🐱 Cat destructor called\n";
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "🐱 Cat copy operator called\n";
	if (this != &src)
	{
		type = src.type;
		delete _brain;
		_brain = new Brain(*src._brain); 
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "🐱 Cat: meow\n";
}

void	Cat::setBrainIdea(int i, const std::string& str)
{
	_brain->setIdea(i, str);
}

std::string	Cat::getBrainIdea(int i) const
{
	return (_brain->getIdea(i));
}
