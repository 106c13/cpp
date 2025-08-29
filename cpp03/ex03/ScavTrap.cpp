#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	_keeper = false;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	_keeper = false;
	std::cout << "ScavTrap constructor for " << _name << " called\n";
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	_keeper = src._keeper;
	std::cout << "ScavTrap copy constructor for " << _name << " called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		_keeper = src._keeper;
	}
	std::cout << "ScavTrap copy operator called\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor for " << _name << " called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << _name << " have not enough hit points\n";
	else if (_ep <= 0)
		std::cout << _name << " have not enough energy points\n";
	else
	{
		std::cout << "ScavTrap " << _name
				  << " attacks " << target
				  << ", dealing " << _dmg << " points of damage!\n";
		_ep--;
	}
}

void	ScavTrap::guardGate()
{
	_keeper = true;
	std::cout << "ScavTrap " << _name << " has entered Gate Keeper mode!\n";
}
