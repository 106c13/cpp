#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

AForm* Intern::createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& type, const std::string& target) const
{
	FormType forms[3] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};

	for (int i = 0; i < 3; ++i)
	{
		if (forms[i].name == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return forms[i].creator(target);
		}
	}
	std::cout << "Intern cannot create form: unknown type \"" << type << "\"" << std::endl;
	return (NULL);
}

