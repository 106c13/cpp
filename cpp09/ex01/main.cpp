#include <iostream>
#include <string>

bool	is_valid(std::string input)
{
	std::string	nums = "0123456789";
	std::string	ops = "+-/*";
	int			numsCount = 0;
	int			opsCount = 0;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (nums.find(input[i]) != std::string::npos)
			numsCount++;
		else if (ops.find(input[i]) != std::string::npos)
			opsCount++;
		else if (input[i] != ' ')
			return false;
		if (input[i] != ' ' && numsCount <= opsCount)
			return (false);
	}
	if (numsCount - 1 != opsCount)
		return false;
	return true;
}

int	main(int argc, char** argv)
{
	if (argc != 2 || !is_valid(argv[1]))
	{
		std::cout << "Error\n";
		return 1;
	}
	std::cout << "Input is valid\n";
	return 0;
}
