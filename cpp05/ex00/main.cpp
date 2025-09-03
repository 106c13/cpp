#include <iostream>

int	main()
{
	try
	{
		throw "a";
	}
	catch (int e)
	{
		std::cout << "WTF C++? " << e << std::endl;
	}
	catch (const char* e)
	{
		std::cout << "AAAA " << e << std::endl;
	}
	return (0);
}
