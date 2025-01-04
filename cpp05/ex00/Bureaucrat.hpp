/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:47:16 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/04 02:14:16 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Bureaucrat(const Bureaucrat &copy);
	virtual ~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rvalue);

	void			increaseGrade();
	void			decreaseGrade();

	const std::string	&getName() const;
	int					getGrade() const;

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

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym);

#endif


