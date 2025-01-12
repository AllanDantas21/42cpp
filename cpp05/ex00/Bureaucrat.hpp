#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat{
private:
	std::string _name;
	int 		_grade;

public:
	Bureaucrat(const std::string &_name, int _grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat& operator=(const Bureaucrat& rvalue);
	~Bureaucrat();

	void				increaseGrade();
	void				decreaseGrade();

	const std::string	&getName() const;
	int					getGrade() const;

	class GradeTooHighException : public std::exception {
	 public:
		virtual const char *	what() const throw();
		virtual ~GradeTooHighException() throw() {}
		};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *	what() const throw();
		virtual ~GradeTooLowException() throw() {}
	};
};

std::ostream &	operator<<(std::ostream &o, Bureaucrat const &rSym);

#endif


