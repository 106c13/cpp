#include <iostream>
#include <string>
#include "PhoneBook.hpp"


int main()
{
  PhoneBook pb = PhoneBook();
  std::string  input;

  while (true)
  {
    std::cout << "Input: ";
    std::cin >> input;
    if (input.compare("exit") == 0)
      break ;
    else if (input.compare("add") == 0)
      pb.add_contact();
    else if (input.compare("search") == 0)
      pb.search_contact();
  }
  return (0);
}
