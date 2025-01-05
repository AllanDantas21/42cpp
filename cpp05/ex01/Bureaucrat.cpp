/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:34 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/05 14:48:09 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw std::invalid_argument("Grade is too low!");
	if (grade > 150)
		throw std::invalid_argument("Grade is too high!");
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void	Bureaucrat::increaseGrade() {
	if (this->grade > 1)
		this->grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(){
	if (this->grade < 150)
		this->grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) const
{
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->grade = rvalue.grade;
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym) {
	o << rSym.getName() << ", bureaucrat grade : " << rSym.getGrade();
	return o;
}