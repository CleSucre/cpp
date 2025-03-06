#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PRESIDENTIAL_FORM_NAME "Presidential Pardon"

class PresidentialPardonForm : public AForm {
    private:
    	std::string _target;

	public:
		PresidentialPardonForm();
    	explicit PresidentialPardonForm(std::string target);
    	PresidentialPardonForm(const PresidentialPardonForm &copy);
    	virtual ~PresidentialPardonForm();

    	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

    	virtual void execute(Bureaucrat const &executor) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
