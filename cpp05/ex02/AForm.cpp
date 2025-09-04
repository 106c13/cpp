#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_name("Default"), 
	_signed(false),
	_signGrade(150),
	_executeGrade(150)
{
	std::cout << "Form Default created";
}

Form::Form(const std::string& name, int signGrade, int executeGrade) :
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

Form::~Form()
{
	std::cout << "Form " << _name << " deleted\n";
}

Form&	Form::operator=(const Form& src)
{
	if (this == &src)
		return (*this);
	std::cout << "Copying Form from " << _name << " to " << src._name << std::endl;
	_signed = src._signed;
	return (*this);
}

void	Form::beSigned(const Bureaucrat& b)
{
	const int grade = b.getGrade();

	if (grade > _signGrade)
		throw GradeTooLowException();
	std::cout << b.getName() << " signed form " << _name << std::endl;
	_signed = true;
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::isSigned() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (_executeGrade);
}

const char*	Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& o, Form const& form)
{
	o << "Name: " << form.getName()
	  << "\nSign grade: " << form.getSignGrade()
	  << "\nExecute grade: " << form.getExecuteGrade();
	o << "\nForm is " << (form.isSigned() ? "signed" :"not signed");
	return (o);
}
