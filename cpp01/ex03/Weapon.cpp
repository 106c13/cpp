#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string w_type)
{
	type = w_type;
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string value)
{
	type = value;
}
