#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie	z1 = Zombie("Karl");
	z1.announce();
	Zombie	*z2 = newZombie("Smith");
	z2->announce();
	randomChump("Luke");
	delete z2;
	return (0);
}
