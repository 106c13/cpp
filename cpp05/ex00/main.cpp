#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("Karl", 2);

		std::cout << b1 << std::endl;	
		std::cout << "Incrementing grade..." << std::endl;
		b1.incrementGrade();
		std::cout << b1.getName() << " now has grade " << b1.getGrade() << std::endl;

		std::cout << "Incrementing grade again (should throw)..." << std::endl;
		b1.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "===================================================\n";
	try
	{
		Bureaucrat	b2("Bob", 150);
		Bureaucrat	b3 = b2;
		std::cout << b3.getName() << " has grade " << b3.getGrade() << std::endl;
		std::cout << "Decrementing grade..." << std::endl;
		b3.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
