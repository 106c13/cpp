#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string type;

	if (argc != 2)
	{
		std::cout << "Wrong argument count\n";
		return (1);
	}
	type = argv[1];
	if (type.compare("DEBUG") == 0)
		harl.complain(0);	
	else if (type.compare("INFO") == 0)
		harl.complain(1);	
	else if (type.compare("WARNING") == 0)
		harl.complain(2);	
	else if (type.compare("ERROR") == 0)
		harl.complain(3);	
	else
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	return (0);
}

