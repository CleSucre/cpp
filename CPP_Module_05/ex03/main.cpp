#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.h"
#include <iostream>

void printHeader(std::string title) {
    std::cout << BOLD << CYAN << "\n===== " << title << " =====\n" << RESET << std::endl;
}

void tryExecute(Bureaucrat &b, AForm *form) {
    if (!form) return;
    if (!form->isSigned()) {
        std::cerr << BOLD << RED << "Error: Cannot execute " << form->getName()
                  << " because it is not signed!" << RESET << std::endl;
        return;
    }
    try {
        b.executeForm(*form);
    } catch (std::exception &e) {
        std::cerr << BOLD << RED << b.getName() << " couldn't execute "
                  << form->getName() << " because: " << e.what() << RESET << std::endl;
    }
}

void trySign(Bureaucrat &b, AForm *form) {
    if (!form) return;
    if (form->isSigned()) {
        std::cout << BOLD << YELLOW << form->getName() << " is already signed." << RESET << std::endl;
        return;
    }
    b.signForm(*form);
}

int main() {
    printHeader("TESTING INTERN FORM CREATION");

    Intern someRandomIntern;

    Bureaucrat highRank("Alice", 1);
    Bureaucrat midRank("Bob", 50);
    Bureaucrat lowRank("Charlie", 150);

    printHeader("CREATING FORMS WITH INTERN");
    AForm *shrubbery = someRandomIntern.makeForm(SHRUBBERY_FORM_NAME, "Home");
    AForm *robotomy = someRandomIntern.makeForm(ROBOTOMY_FORM_NAME, "TargetX");
    AForm *pardon = someRandomIntern.makeForm(PRESIDENTIAL_FORM_NAME, "Prisoner42");
    AForm *unknown = someRandomIntern.makeForm("unknown form", "Nowhere");

    printHeader("SIGNING FORMS");
    trySign(lowRank, shrubbery);
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

    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unknown;

    printHeader("TESTS COMPLETED");
    return 0;
}
