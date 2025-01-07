/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:47:16 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/06 22:28:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	std::string name;
	int grade;

public:
	// Constructors
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	virtual ~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rvalue);

	// Member functions
	void			increaseGrade();
	void			decreaseGrade();
	void			signForm(AForm& form) const;
	void			executeForm(AForm const & form) const;

	// Getters
	const std::string	&getName() const;
	int					getGrade() const;

	// Exceptions
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
};

// Overload operator
std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym);

#endif


