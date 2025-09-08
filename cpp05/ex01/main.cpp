#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		Bureaucrat bob("Bob", 50);
		Bureaucrat mark("Mark", 1);

		std::cout << bob << std::endl;
		std::cout << mark << std::endl;
		Form formA("FormA", 30, 20);
		Form formB("FormB", 1, 1);

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
		mark.signForm(formA);
		bob.signForm(formB);
		std::cout << formA << std::endl;
	}
	//Form invalidForm("InvalidForm", 0, 151);
    return 0;
}

