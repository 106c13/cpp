#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int     _index;
	int		_count;

public:
	PhoneBook();
	~PhoneBook();
	void	add_contact();
	void	search_contact();
};

#endif
