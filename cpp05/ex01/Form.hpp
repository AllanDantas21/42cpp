/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:27:50 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 17:05:06 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_exec;
	public:
		// Constructors
		Form(const std::string& name, const int grade_to_sign, const int grade_to_exec);
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