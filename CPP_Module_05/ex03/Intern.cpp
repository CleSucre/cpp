#include "Intern.hpp"
#include "colors.h"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	(void)copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

// Méthodes statiques pour créer les formulaires
AForm *Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {
		SHRUBBERY_FORM_NAME,
		ROBOTOMY_FORM_NAME,
		PRESIDENTIAL_FORM_NAME
	};

	AForm* (*formConstructors[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
			return (*formConstructors[i])(target);
		}
	}

	std::cerr << RED << "Error: Form '" << formName << "' does not exist!" << RESET << std::endl;
	return NULL;
}
