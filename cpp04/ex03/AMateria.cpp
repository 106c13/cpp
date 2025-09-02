#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown")
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const AMateria& src) : _type(src._type)
{
	std::cout << "AMateria copy constructor called\n";
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << "AMateria constructor with string argument called\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

AMateria&	AMateria::operator=(const AMateria& src)
{
	std::cout << "AMateria copy operator called\n";
	if (this != &src)
	_type = src._type;
	return *this;
}

std::string const&	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "AMateria base use() called (does nothing)\n";
}

