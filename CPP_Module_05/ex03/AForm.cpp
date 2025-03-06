#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

AForm::AForm() :
	_name("form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &copy) :
	_name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy) {
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_isSigned) {
		std::cerr << BOLD << YELLOW << "Warning: Form " << this->getName()
				  << " is already signed!" << RESET << std::endl;
		return;
	}
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
	std::cout << BOLD << GREEN << bureaucrat.getName() << " signed " << this->getName() << RESET << std::endl;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::isSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form: " << form.getName() << ", Required Sign Grade: " << form.getGradeToSign()
		<< ", Required Execute Grade: " << form.getGradeToExecute()
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return out;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}
