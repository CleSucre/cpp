#include "Bureaucrat.hpp"
#include "colors.h"
#include <iostream>

int main() {
    std::cout << BOLD << CYAN << "\n===== TESTING BUREAUCRAT CREATION =====\n" << RESET << std::endl;

    try {
        Bureaucrat b1("Alice", 42);
        Bureaucrat b2("Bob", 1);
        Bureaucrat b3("Charlie", 150);

        std::cout << BOLD << GREEN << "Valid Bureaucrats created successfully:\n" << RESET;
        std::cout << YELLOW << b1 << RESET << std::endl;
        std::cout << YELLOW << b2 << RESET << std::endl;
        std::cout << YELLOW << b3 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << CYAN << "\n===== TESTING INVALID GRADES =====\n" << RESET << std::endl;

    try {
        Bureaucrat b4("TooHigh", 0);
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b5("TooLow", 151);
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << CYAN << "\n===== TESTING GRADE MODIFICATIONS =====\n" << RESET << std::endl;

    Bureaucrat b6("David", 75);
    std::cout << BOLD << YELLOW << "Initial: " << RESET << b6 << std::endl;

    try {
        b6.increaseGrade();
        std::cout << BOLD << GREEN << "After increase: " << RESET << b6 << std::endl;

        b6.decreaseGrade();
        std::cout << BOLD << GREEN << "After decrease: " << RESET << b6 << std::endl;

        Bureaucrat b7("EdgeCase", 1);
        std::cout << BOLD << YELLOW << "\nTesting edge case (Grade 1)...\n" << RESET;
        b7.increaseGrade();
    }
    catch (std::exception &e) {
        std::cerr << BOLD << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD << MAGENTA << "\n===== TESTS COMPLETED =====\n" << RESET << std::endl;
    return 0;
}
