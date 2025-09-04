#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        Form formA("FormA", 30, 20);
        Form formB("FormB", 1, 1);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        // Bob tries to sign formA (should fail)
        try {
            formA.beSigned(bob);
        } catch (const std::exception& e) {
            std::cerr << "Bob couldn't sign FormA because: " << e.what() << std::endl;
        }

        // Alice signs formA (should succeed)
        try {
            formA.beSigned(alice);
            std::cout << "Alice successfully signed FormA" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Alice couldn't sign FormA because: " << e.what() << std::endl;
        }

        std::cout << formA << std::endl;

        // Alice signs formB (should succeed)
        try {
            formB.beSigned(alice);
            std::cout << "Alice successfully signed FormB" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Alice couldn't sign FormB because: " << e.what() << std::endl;
        }

        // Attempt invalid form
        try {
            Form invalidForm("InvalidForm", 0, 151);
        } catch (const std::exception& e) {
            std::cerr << "Cannot create InvalidForm: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}

