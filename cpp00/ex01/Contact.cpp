#include <string>
#include "Contact.hpp"

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone = "";
	_secret = "";
}

void	Contact::set_first_name(const std::string &first_name)
{
	_first_name = first_name;
}

void	Contact::set_last_name(const std::string &last_name)
{
	_last_name = last_name;
}

void	Contact::set_nickname(const std::string &nickname)
{
	_nickname = nickname;
}

void	Contact::set_phone(const std::string &phone)
{
	_phone = phone;
}

void	Contact::set_secret(const std::string &secret)
{
	_secret = secret;
}

const std::string&	Contact::get_first_name(void)
{
	return (_first_name);
}

const std::string&	Contact::get_last_name()
{
	return (_last_name);
}

const std::string&	Contact::get_nickname()
{
	return (_nickname);
}

const std::string&	Contact::get_phone()
{
	return (_phone);
}

const std::string&	Contact::get_secret()
{
	return (_secret);
}
