#include <iostream>
#include <string>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
	_hp = 100;
	_ep = 100;
	_dmg = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 100;
	_dmg = 30;
	std::cout << "FragTrap constructor for " << _name << " called\n";
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor for " << _name << " called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	std::cout << "FragTrap copy operator called\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor for " << _name << " called\n";
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " high five!!!\n";
}
