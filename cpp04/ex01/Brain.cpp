#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain&	Brain::operator=(const Brain& src)
{
	std::cout << "Brain copy operator called\n";
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return (*this);
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i > 100)
		return ("");
	return (ideas[i]);
}

void	Brain::setIdea(int i, const std::string& str)
{
	if (i < 0 || i > 100)
	{
		std::cout << "Index should be from 0 to 100\n";
		return ;
	}
	ideas[i] = str;
}
