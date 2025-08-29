#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	*d1 = new DiamondTrap("Noy");
	DiamondTrap *d2 = new DiamondTrap(*d1);
	DiamondTrap *d3 = new DiamondTrap(*d2);
	DiamondTrap	d4 = *d3;

	d1->whoAmI();
	d2->whoAmI();
	d3->whoAmI();
	d4.whoAmI();

	delete d1;
	delete d2;
	delete d3;
	return (0);
}
