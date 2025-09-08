#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
private:
	std::string	_name;
	int			_grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& src);
	
	const std::string&	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm& form);
	void       			executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
    {
		public:
	        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
		public:
	        const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);

#endif
