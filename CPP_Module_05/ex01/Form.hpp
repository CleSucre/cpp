#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
    	Form();
    	Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
    	~Form();

        Form &operator=(const Form &copy);

		void beSigned(const Bureaucrat &burecrat);

        std::string getName() const;
        bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif //FORM_HPP
