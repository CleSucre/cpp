#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(ROBOTOMY_FORM_NAME, 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm(ROBOTOMY_FORM_NAME, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned()) {
		throw FormNotSignedException();
	}

	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
	}

	static bool seedInitialized = false;
	if (!seedInitialized) {
		std::srand(std::time(NULL));
		seedInitialized = true;
	}

	std::cout << YELLOW << "Bzzzzzzzzz" << RESET << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << MAGENTA << this->_target << GREEN << " has been robotomized successfully!" << RESET << std::endl;
	} else {
		std::cout << MAGENTA << this->_target << RED << " robotomization failed!" << RESET << std::endl;
	}
}
