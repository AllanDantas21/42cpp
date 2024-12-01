#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
	std::string name;
	int grade;

public:
	Bureaucrat(const std::string &name, int grade);
	void signForm(Form &form);

	const std::string &getName() const;
	int getGrade() const;
};

#endif


