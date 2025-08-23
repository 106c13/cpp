#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string  get_input(std::string message)
{
  std::string input;

  input = "";
  while (input.length() == 0)
  {
    std::cout << message;
    std::getline(std::cin, input);
  }
  return (input);
}

static void print_field(const std::string& field, const std::string& after)
{
  int size = field.length();

  if (size > 10)
    std::cout << field.substr(0, 9) << "." << after;
  else
    std::cout << std::string((10 - size), ' ') << field <<  after;
}

PhoneBook::PhoneBook()
{
  index = 0;
}

PhoneBook::~PhoneBook()
{
  std::cout << "Phonebook closed" << std::endl;
}

void PhoneBook::add_contact()
{
  std::string first_name = get_input("First name: ");
  std::string last_name  = get_input("Last name: ");
  std::string nickname   = get_input("Nickname: ");
  std::string phone      = get_input("Phone: ");
  std::string secret     = get_input("Darkest secret: ");

  contacts[index].set_first_name(first_name);
  contacts[index].set_last_name(last_name);
  contacts[index].set_nickname(nickname);
  contacts[index].set_phone(phone);
  contacts[index].set_secret(secret);
  index = (index + 1) % 8;
  std::cout << "Contaced added" << std::endl;
}

void PhoneBook::search_contact()
{
  int contact_i;

  print_field("     index", "|");
  print_field("first name", "|");
  print_field(" last name", "|");
  print_field("  nickname", "\n");
  for(int i = 0; i < 8; i++)
  {
    if (contacts[i].get_first_name().length() != 0)
    {
      std::cout << "         " << i + 1 << "|";
      print_field(contacts[i].get_first_name(), "|");
      print_field(contacts[i].get_last_name(), "|");
      print_field(contacts[i].get_nickname(), "\n");
    }
    else
      break ;
  }
  std::cout << "Index: ";
  while (!(std::cin >> contact_i))
  {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid input. Try again: ";
  }
  std::cin.ignore(10000, '\n');
  if (contact_i < 1 || contact_i > 7)
  {
    std::cout << "Invalid index" << std::endl;
    return ;
  }
  if (contacts[contact_i - 1].get_first_name().length() != 0)
  {
    std::cout << contacts[contact_i - 1].get_first_name() << std::endl;
    std::cout << contacts[contact_i - 1].get_last_name() << std::endl;
    std::cout << contacts[contact_i - 1].get_nickname() << std::endl;
    std::cout << contacts[contact_i - 1].get_phone() << std::endl;
    std::cout << contacts[contact_i - 1].get_secret() << std::endl;
  }
}
