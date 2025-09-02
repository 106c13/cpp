#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice& src) : AMateria(src)
{
	std::cout << "Ice copy constructor called\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

Ice& Ice::operator=(const Ice& src)
{
	std::cout << "Ice copy assignment operator called\n";
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *\n";
}
