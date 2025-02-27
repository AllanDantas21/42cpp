#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		AForm();
	public:
		// Constructors
		AForm(const std::string& name, const int grade_to_sign, const int grade_to_exec);
		AForm(const AForm& instance);
		AForm& operator=(const AForm& rvalue);
		virtual ~AForm();

		// Getters
		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

		// Methods
		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executer) const = 0;

		// Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedFormException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedFormException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& rvalue);

#endif