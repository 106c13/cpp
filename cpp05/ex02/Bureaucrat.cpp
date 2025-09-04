#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() :
	_name("Default"),
	_grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " constructed with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) :
	_name(src._name)
{
    _grade = src._grade;
    std::cout << "Bureaucrat " << _name << " copy constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destroyed\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
        _grade = src._grade;
    return (*this);
}

std::string	Bureaucrat::getName() const
{
    return (_name);
}

int	Bureaucrat::getGrade() const
{
    return (_grade);
}

void	Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void	Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << _name << " couldn’t sign " << form.getName() 
				  << " reason " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
	o << b.getName() << " bureaucrat grade " << b.getGrade();
	return (o);
}
