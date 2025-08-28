#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "Default contructor for called\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor for " << _name << " called\n";
	if (this != src)
	{
		_name = src._name;
		_hp = src._hp;
		_ep = src._ep;
		_dmg = src._dmg;
	}
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy operator constructor for " << _name << " called\n";
	if (this == src)
		return (*this);
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_dmg = src._dmg;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for " << _name << " called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "Contructor for " << _name << " called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << _name << " have not enough hit points\n";
	else if (_ep <= 0)
		std::cout << _name << " have not enough energy points\n";
	else
	{
		std::cout << "ClapTrap "
				  << _name
				  << " attacks "
				  << target
				  << ", causing "
				  << _dmg
				  << " points of damage!\n";
		_ep--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << _name << " already dead\n";
		return ;
	}
	std::cout << "ClapTrap "
			  << _name
			  << " took damage -"
			  << amount
			  << std::endl;
	_hp -= amount;
	if (_hp <= 0)
	{
		_hp = 0;
		std::cout << _name << " died\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
		std::cout << _name << " have not enough hit points\n";
	else if (_ep <= 0)
		std::cout << _name << " have not enough energy points\n";
	else
	{
		std::cout << "ClapTrap "
				  << _name
				  << " repaired +"
				  << amount
				  << std::endl;
		_hp += amount;
		_ep--;
	}
}
