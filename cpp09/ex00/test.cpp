#include <iostream>
#include <string>
#include <map>

int	main()
{
	std::map<std::string, int>users;

	users["Mark"] = 10;
	users["John"] = 2;
	for (std::map<std::string,int>::iterator it = users.begin(); it != users.end(); ++it) {
    	std::cout << "Name: " << it->first
				  << " " << &it->first
				  << " " << it->second
				  << " " << &it->second
				  << std::endl;
	}

	return 0;
}
