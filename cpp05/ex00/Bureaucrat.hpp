#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class	Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	Bureaucrat(std::string name, int grade);
	
	std::string	getName();
	int			getGrade();
};

#endif
