#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.h"
#include <iostream>

int main() {
    std::cout << BOLD << CYAN << "\n===== TESTING FORM SIGNING =====\n" << RESET << std::endl;

    try {
        Bureaucrat alice("Alice", 10);
        Form form1("Important Document", 20, 50);

        std::cout << BOLD << YELLOW << "Before signing: " << RESET << form1 << std::endl;
        alice.signForm(form1);
        std::cout << BOLD << GREEN << "After signing: " << RESET << form1 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 50);
        Form form2("Top Secret", 30, 40);

        std::cout << BOLD << YELLOW << "\nBefore signing: " << RESET << form2 << std::endl;
        bob.signForm(form2);
        std::cout << BOLD << GREEN << "After signing: " << RESET << form2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << MAGENTA << "\nCreating invalid form..." << RESET << std::endl;
        Form invalidForm("Invalid Form", 0, 151);
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << CYAN << "\n===== TESTS COMPLETED =====\n" << RESET << std::endl;
    return 0;
}
