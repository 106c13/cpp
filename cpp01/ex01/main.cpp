#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie *z_arr = zombieHorde(4, "Karl");
	for (int i = 0; i < 4; i++)
	{
		z_arr[i].announce();
	}
	delete[] z_arr;
	return (0);
}
