#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);

    Intern someIntern;

    AForm* shrubForm = someIntern.makeForm("shrubbery creation", "home");
    AForm* robotForm = someIntern.makeForm("robotomy request", "Bender");
    AForm* pardonForm = someIntern.makeForm("presidential pardon", "Marvin");
    AForm* unknownForm = someIntern.makeForm("unknown form", "target");


	if (unknownForm == NULL)
		std::cout << "Unkown form is not created!!\n";
    std::cout << std::endl;

    if (shrubForm)
		std::cout << *shrubForm << std::endl;
    if (robotForm)
		std::cout << *robotForm << std::endl;
    if (pardonForm)
		std::cout << *pardonForm << std::endl;

    std::cout << std::endl;

    if (shrubForm)
		bob.signForm(*shrubForm);
    if (robotForm)
		bob.signForm(*robotForm);
    if (pardonForm)
		alice.signForm(*pardonForm);

    std::cout << std::endl;

    if (shrubForm)
		bob.executeForm(*shrubForm);
    if (robotForm)
		bob.executeForm(*robotForm);
    if (pardonForm)
		alice.executeForm(*pardonForm);

    delete shrubForm;
    delete robotForm;
    delete pardonForm;

    return 0;
}
