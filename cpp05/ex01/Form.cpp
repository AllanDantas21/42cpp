/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:27:47 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 17:05:02 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_exec):
	name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
	if (grade_to_exec > 150 || grade_to_sign > 150)
		throw Form::GradeTooHighException();
	if (grade_to_exec < 1 || grade_to_sign < 1)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy):
	name(copy.name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec)
{}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return (*this);
	is_signed = other.is_signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form]: " << name << " destructed" << std::endl;
}

// Getters
const std::string Form::getName() const { return (name); }
bool Form::getIsSigned() const { return (is_signed); }
int  Form::getGradeToSign() const { return (grade_to_sign); }
int  Form::getGradeToExcute() const { return (grade_to_exec); }

// Methods
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
	{
		if (is_signed)
			throw Form::AlreadySignedFormException();
		is_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

// Overload operator
std::ostream& operator<<(std::ostream& os, const Form& other)
{
	const std::string is_signed_str = other.getIsSigned() ? "true" : "false";
	os 	<< "===== Form ["<< other.getName() << "]=====\n"
		<< "Signed: " << is_signed_str << "\n"
		<< "Grade to sign: " << other.getGradeToSign() << "\n"
		<< "Grade to execute: " << other.getGradeToExcute()
		<< "\n====================";
	return os;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() { return "Grade is too high for form"; }
const char* Form::GradeTooLowException::what() const throw() { return "Grade is too low for form"; }
const char* Form::AlreadySignedFormException::what() const throw() { return "Form is already signed"; }
