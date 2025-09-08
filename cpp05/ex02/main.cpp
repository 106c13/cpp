#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat  b1("Jim", 2);
    Bureaucrat  b2("Bob", 150);
    RobotomyRequestForm f1("home");
    ShrubberyCreationForm f2("school");
    PresidentialPardonForm f3("work");

    b1.signForm(f1);
    b2.signForm(f2);
    b1.signForm(f3);

    b1.executeForm(f1);
    b2.executeForm(f1);
    return 0;
}

