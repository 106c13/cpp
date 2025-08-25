#include <iostream>
#include <string>
#include "PhoneBook.hpp"

static std::string get_input(const std::string &message)
{
	std::string input;

	std::cout << message;
	if (!std::getline(std::cin, input))
		return ("");
	return (input);
}

int main()
{
	PhoneBook	pb = PhoneBook();
	std::string	input;

	while (true)
	{
		input = get_input("Input: ");
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("ADD") == 0)
			pb.add_contact();
		else if (input.compare("SEARCH") == 0)
			pb.search_contact();
		else if (input.empty() && std::cin.eof())
			break ;
	}
	return (0);
}
