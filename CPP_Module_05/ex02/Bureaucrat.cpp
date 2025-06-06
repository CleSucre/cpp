#include "Bureaucrat.hpp"
#include "colors.h"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
	this->setGrade(other._grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << BOLD << GREEN << this->getName() << " executed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << BOLD << RED << this->getName() << " couldn't execute " << form.getName()
		          << " because " << e.what() << RESET << std::endl;
	}
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increaseGrade() {
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decreaseGrade() {
	this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cerr << BOLD << RED << this->getName() << " couldn't sign " << form.getName()
		          << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::setGrade(const int grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
