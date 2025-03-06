#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();

		Intern &operator=(const Intern &copy);

		AForm *makeForm(std::string formName, std::string target);

	private:
		static AForm *createShrubbery(std::string target);
		static AForm *createRobotomy(std::string target);
		static AForm *createPardon(std::string target);
};

#endif // INTERN_HPP
