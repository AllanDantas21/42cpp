
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	~Form();

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif