#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
protected:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_dmg;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& src);
	ClapTrap&	operator=(const ClapTrap& src);
	ClapTrap(std::string name);
	virtual		~ClapTrap();
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
#endif
