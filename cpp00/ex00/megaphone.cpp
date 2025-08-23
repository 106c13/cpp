#include <iostream>
#include <stdio.h>

void	print_argv(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		std::cout << *str;
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*(++argv))
			print_argv(argv[0]);
		std::cout << std::endl;
	}
  return (0);
}
