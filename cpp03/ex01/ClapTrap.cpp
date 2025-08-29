#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "ClapTrap default contructor for " << _name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap copy constructor for " << _name << " called\n";
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_dmg = src._dmg;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap copy operator for " << _name << " called\n";
	if (this == &src)
		return (*this);
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_dmg = src._dmg;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor for " << _name << " called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "ClapTrap contructor for " << _name << " called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp <= 0)
		std::cout << _name << " have not enough hit points\n";
	else if (_ep <= 0)
		std::cout << _name << " have not enough energy points\n";
	else
	{
		std::cout << "ClapTrap " << _name
				  << " attacks " << target
				  << ", causing " << _dmg << " points of damage!\n";
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
