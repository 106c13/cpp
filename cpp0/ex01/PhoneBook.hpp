#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
  Contact contacts[8];
  int     index;
public:
  PhoneBook();
  ~PhoneBook();
  void  add_contact();
  void  search_contact();
};

#endif
