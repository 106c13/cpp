#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	c1("John");
	ClapTrap	c2("Karlos");

	c1.attack("Karlos");
	c2.takeDamage(3);
	c2.attack("John");
	c1.takeDamage(5);
	c1.beRepaired(5);
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	c1.attack("Karlos");
	return (0);
}
