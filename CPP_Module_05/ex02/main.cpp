#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.h"
#include <iostream>

void printHeader(std::string title) {
    std::cout << BOLD << CYAN << "\n===== " << title << " =====\n" << RESET << std::endl;
}

void tryExecute(Bureaucrat &b, AForm &form) {
    if (!form.isSigned()) {
        std::cerr << BOLD << RED << "Error: Cannot execute " << form.getName()
                  << " because it is not signed!" << RESET << std::endl;
        return;
    }
    try {
        b.executeForm(form);
    } catch (std::exception &e) {
        std::cerr << BOLD << RED << b.getName() << " couldn't execute "
                  << form.getName() << " because: " << e.what() << RESET << std::endl;
    }
}

void trySign(Bureaucrat &b, AForm &form) {
    if (form.isSigned()) {
        std::cout << BOLD << YELLOW << form.getName() << " is already signed." << RESET << std::endl;
        return;
    }
    b.signForm(form);
}

int main() {
    printHeader("TESTING FORM EXECUTION");

    Bureaucrat highRank("Alice", 1);
    Bureaucrat midRank("Bob", 50);
    Bureaucrat lowRank("Charlie", 150);
    Bureaucrat weakBureaucrat("Dave", 148);
    Bureaucrat almostTopBureaucrat("Eve", 2);

    printHeader("CREATING FORMS");
    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("TargetX");
    PresidentialPardonForm pardon("Prisoner42");

    std::cout << YELLOW << shrubbery << RESET << std::endl;
    std::cout << YELLOW << robotomy << RESET << std::endl;
    std::cout << YELLOW << pardon << RESET << std::endl;

    printHeader("TRYING TO EXECUTE FORMS WITHOUT SIGNING");
    tryExecute(highRank, shrubbery);
    tryExecute(midRank, robotomy);
    tryExecute(lowRank, pardon);

    printHeader("SIGNING FORMS");
    trySign(lowRank, shrubbery);
    trySign(midRank, shrubbery);
    trySign(midRank, robotomy);
    trySign(almostTopBureaucrat, pardon);
    trySign(highRank, pardon);

    printHeader("TRYING TO SIGN ALREADY SIGNED FORMS");
    trySign(midRank, shrubbery);
    trySign(midRank, robotomy);
    trySign(highRank, pardon);

    printHeader("EXECUTING FORMS WITH HIGH-RANK BUREAUCRAT");
    tryExecute(highRank, shrubbery);
    tryExecute(highRank, robotomy);
    tryExecute(highRank, pardon);

    printHeader("MULTIPLE ROBOTOMY ATTEMPTS TO TEST 50% SUCCESS RATE");
    for (int i = 0; i < 5; i++) {
        tryExecute(highRank, robotomy);
    }

    printHeader("TRYING TO EXECUTE FORMS WITH LOW-RANK BUREAUCRATS");
    tryExecute(lowRank, shrubbery);
    tryExecute(weakBureaucrat, robotomy);
    tryExecute(weakBureaucrat, pardon);

    printHeader("TESTS COMPLETED");
    return 0;
}
