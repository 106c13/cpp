#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	std::cout << "Cure copy constructor called\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

Cure& Cure::operator=(const Cure& src)
{
	std::cout << "Cure copy assignment operator called\n";
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure: * heals " << target.getName() << "’s wounds *\n";
}
