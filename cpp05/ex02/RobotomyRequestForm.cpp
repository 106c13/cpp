#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") 
{
    std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
    std::cout << "RobotomyRequestForm created for target " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) 
{
    std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm for target " << _target << " destroyed\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << "BZZZZZZT! DRILLING NOISES...\n";

    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed for " << _target << "...\n";
}

