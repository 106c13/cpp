#include <iostream>
#include "Character.hpp"

Character::Character() : _name("Default")
{
	std::cout << "Character default constructor called\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character constructor with name called\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	std::cout << "Character copy constructor called\n";
	*this = src;
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character&	Character::operator=(Character const & src)
{
	std::cout << "Character copy operator called\n";
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
		{
			std::cout << "Can't equip twice\n";
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << " equips " << m->getType() << " in slot " << i << "\n";
			return;
		}
	}
	std::cout << _name << " has no space to equip " << m->getType() << "\n";
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	std::cout << _name << " unequips " << _inventory[idx]->getType() << " from slot " << idx << "\n";
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (!_inventory[idx])
	{
		std::cout << "Slot " << idx << " is empty\n";
		return ;
	}
	_inventory[idx]->use(target);
}
