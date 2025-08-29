#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	c1("Max");
	ScavTrap*	s1 = new ScavTrap("Mini");
	FragTrap	f1("Fam");
	FragTrap	f2(f1);

	f2 = f1;
	c1.attack("Mini");
	s1->attack("Max");
	f1.attack("Max");
	delete s1;
	return (0);
}
