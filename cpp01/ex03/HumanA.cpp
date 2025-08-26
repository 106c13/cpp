#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string h_name, Weapon& h_weapon) : name(h_name), weapon(h_weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << name
			  << " attacks with their "
			  << weapon.getType()
			  << std::endl;
}
