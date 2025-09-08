#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& src);
	~Intern();

	Intern&	operator=(const Intern& src);

	AForm*	makeForm(const std::string& type, const std::string& target) const;

private:
	struct FormType
	{
		std::string name;
		AForm*	(*creator)(const std::string& target);
	};
	static AForm*	createShrubbery(const std::string& target);
	static AForm*	createRobotomy(const std::string& target);
	static AForm*	createPresidential(const std::string& target);
};

#endif

