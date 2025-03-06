#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		explicit RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		virtual void execute(Bureaucrat const &executor) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
