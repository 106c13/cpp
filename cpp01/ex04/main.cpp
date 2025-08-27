#include <iostream>
#include <string>
#include "replace.hpp"



int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Not enough arguments\n";
		return (1);
	}
	if (!argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout << "Empty argument\n";
		return (1);
	}
	replaceFileContent(argv[1], argv[2], argv[3]);
	return (0);
}
