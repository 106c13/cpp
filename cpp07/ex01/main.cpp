#include <iostream>
#include "template.hpp"

void	add(int n)
{
	n++;
	std::cout << n << std::endl;
}

void	rot13(char c)
{
	if ((c >= 'a' && c <= 'n') || (c >= 'A' && c <= 'N'))
		c += 13;
	else if ((c >= 'm' && c <= 'z') || (c >= 'M' && c <= 'Z'))
		c -= 13;

	std::cout  << c;
}

int main()
{
	int			arr[3] = {1, 2, 3};
	char const*	arr1 = "Hello world\n";

	iter(arr, 3, add);
	iter(arr1, 12, rot13);
}
