#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
private:
	std::string	name;
	Weapon&	weapon;
public:
	HumanA(std::string h_name, Weapon& h_weapon);
	~HumanA();
	void	attack( void );
};

#endif
