#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
	_name("Default"), 
	_signed(false),
	_signGrade(150),
	_executeGrade(150)
{
	std::cout << "Form Default created";
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) :
	_name(name),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	_signed = false;
	std::cout << "Form " << _name << " created\n";
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " deleted\n";
}

AForm&	AForm::operator=(const AForm& src)
{
	if (this == &src)
		return (*this);
	std::cout << "Copying Form from " << _name << " to " << src._name << std::endl;
	_signed = src._signed;
	return (*this);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	const int grade = b.getGrade();

	if (grade > _signGrade)
		throw GradeTooLowException();
	std::cout << b.getName() << " signed form " << _name << std::endl;
	_signed = true;
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::isSigned() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream&	operator<<(std::ostream& o, AForm const& form)
{
	o << "Name: " << form.getName()
	  << "\nSign grade: " << form.getSignGrade()
	  << "\nExecute grade: " << form.getExecuteGrade();
	o << "\nForm is " << (form.isSigned() ? "signed" :"not signed");
	return (o);
}
