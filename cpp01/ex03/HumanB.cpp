#include <string>
#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string h_name) : name(h_name)
{
	weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (!weapon)
	{
		std::cout << name << " doesn't have a weapon\n";
		return ;
	}
	std::cout << name
			  << " attacks with their "
			  << weapon->getType()
			  << std::endl;
}

void	HumanB::setWeapon(Weapon& n_weapon)
{
	weapon = &n_weapon;
}
