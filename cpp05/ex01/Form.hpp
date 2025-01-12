#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
	public:
		// Constructors
		Form(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec);
		Form(const Form& instance);
		Form& operator=(const Form& rvalue);
		~Form();

		// Getters
		const std::string getName() const;
		bool			  getIsSigned() const;
		int				  getGradeToSign() const;
		int				  getGradeToExcute() const;

		// Methods
		void beSigned(const Bureaucrat& bureaucrat);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// overloads
};

std::ostream& operator<<(std::ostream& os, const Form& rvalue);

#endif