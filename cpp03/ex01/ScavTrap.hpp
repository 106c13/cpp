#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClavTrap.hpp"

class	ScavTrap : public 
{
private:
	std::string	name;
	int			_hp;
	int			_ep;
	int			_dmg;
public:
	ScavTrap();
	ScavTrap(const ScapTrap& src);
	ScavTrap&	operator=(const ScavTrap& src);
	~ScavTrap();

	void	guardGate(void);
};

#endif
