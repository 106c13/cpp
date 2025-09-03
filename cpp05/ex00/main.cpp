#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1.getName() << " has grade " << b1.getGrade() << std::endl;

		std::cout << "Incrementing grade..." << std::endl;
		b1.incrementGrade();
		std::cout << b1.getName() << " now has grade " << b1.getGrade() << std::endl;

		std::cout << "Incrementing grade again (should throw)..." << std::endl;
		b1.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
