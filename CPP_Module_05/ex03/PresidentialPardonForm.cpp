#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm(PRESIDENTIAL_FORM_NAME, 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm(PRESIDENTIAL_FORM_NAME, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned()) {
		throw FormNotSignedException();
	}

	if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
	}

    std::cout << MAGENTA << this->_target << GREEN << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
