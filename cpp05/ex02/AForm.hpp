#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	const std::string	_name;
	bool		_signed;
	const int	_signGrade;
	const int	_executeGrade;

public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	~AForm();

	AForm&	operator=(const AForm& src);

	void				beSigned(const Bureaucrat& b);
	const std::string&	getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

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

std::ostream & operator<<(std::ostream & o, Form const & form);

#endif
