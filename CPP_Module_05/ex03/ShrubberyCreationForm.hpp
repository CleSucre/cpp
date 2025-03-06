#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_FORM_NAME "Shrubbery Creation"

class ShrubberyCreationForm : public AForm {
  	private:
          std::string _target;

	public:
		ShrubberyCreationForm();
		explicit ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		virtual void execute(Bureaucrat const &executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
