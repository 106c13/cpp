#include "ScavTrap.hpp"


int	main()
{
	ScavTrap	s1("Rex");
	ScavTrap	s2(s1);
	ClapTrap	*s3 = new ScavTrap(s2);
	s2.attack("John");
	delete s3;
	return (0);
}
