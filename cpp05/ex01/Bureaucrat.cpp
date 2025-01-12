/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:34 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 17:40:22 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// constructors & destructors
Bureaucrat::Bureaucrat(const std::string &name, int _grade) : name(name), _grade(_grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), _grade(copy._grade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rvalue) {
	if (this == &rvalue)
		return (*this);
	this->_grade = rvalue._grade;
	return (*this);
}

// getters
const std::string &Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return _grade; }

// methods
void Bureaucrat::increaseGrade(){
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(){
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) const {
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() { return "grade is too high!"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "grade is too low!"; }

// overloads
std::ostream &operator<<(std::ostream & o, Bureaucrat const &rSym) {
	o << rSym.getName() << ", bureaucrat grade : " << rSym.getGrade();
	return o;
}