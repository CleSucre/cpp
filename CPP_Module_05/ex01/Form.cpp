#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

Form::Form() :
	_name("form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &copy) :
	_name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form::~Form() {}

Form &Form::operator=(const Form &copy) {
	if (this != &copy) {
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
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

std::string Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form: " << form.getName() << ", Required Sign Grade: " << form.getGradeToSign()
		<< ", Required Execute Grade: " << form.getGradeToExecute()
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return out;
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}