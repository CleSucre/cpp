#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned()) {
    	throw FormNotSignedException();
	}

    if (executor.getGrade() > this->getGradeToExecute()) {
		throw GradeTooLowException();
    }

    std::string target = this->_target + "_shrubbery";
    std::ofstream file(target.c_str());
    if (!file) {
    	std::cerr << RED << "Couldn't create file " << MAGENTA << target << RESET << std::endl;
		return;
    }

    file << "  A " << std::endl << " / \\" << std::endl << " B  C" << std::endl << std::endl;
    file << "  X " << std::endl << " / \\" << std::endl << " Y  Z" << std::endl;
    std::cout << GREEN << "ASCII trees have been written into " << MAGENTA << target << RESET << std::endl;
}
