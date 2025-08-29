#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
private:
	bool	_keeper;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& src);
	ScavTrap&	operator=(const ScavTrap& src);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
