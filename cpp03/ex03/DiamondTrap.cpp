#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default")
{
	_hp = 100;
	_ep = 50;
	_dmg = 30;
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hp = 100;
	_ep = 50;
	_dmg = 30;
	std::cout << "DiamondTrap constructor for " << _name << " called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), _name(src._name)
{
	std::cout << "DiamondTrap copy constructor for " << _name << " called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		_name = src._name;
	}
	std::cout << "DiamondTrap copy operator called\n";
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor for " << _name << " called\n";
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name
			  << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
