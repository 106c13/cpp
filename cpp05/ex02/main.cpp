#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // Create Bureaucrats
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);

    std::cout << bob << std::endl;
    std::cout << alice << std::endl;

    // Create Forms
    ShrubberyCreationForm treeForm("home");

    std::cout << treeForm << std::endl;

    // Bob tries to sign the form (grade 50, form requires 145)
    bob.signForm(treeForm);

    // Print form status
    std::cout << treeForm << std::endl;

    // Alice executes the form
    alice.executeForm(treeForm);

    // Print form info again
    std::cout << treeForm << std::endl;

    return 0;
}

