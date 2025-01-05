#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
	std::string name;
	int grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();


	void			increaseGrade();
	void			decreaseGrade();
	class GradeTooHighException : public std::exception{
			public:
				virtual const char *	what() const throw();
				virtual ~GradeTooHighException() throw() {}
		};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char *	what() const throw();
			virtual ~GradeTooLowException() throw() {}
	};
	const std::string &getName() const;
	int getGrade() const;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym);

#endif


