#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

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
	
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

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

#endif
