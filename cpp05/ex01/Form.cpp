#include "Form.hpp"

// Constructors
Form::Form(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec):
	_name(_name), _is_signed(false), _grade_to_sign(_grade_to_sign), _grade_to_exec(_grade_to_exec)
{
	if (_grade_to_exec > 150 || _grade_to_sign > 150)
		throw Form::GradeTooHighException();
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy):
	_name(copy._name), _is_signed(copy._is_signed), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec)
{}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return (*this);
	_is_signed = other._is_signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form]: " << _name << " destructed" << std::endl;
}

// Getters
const std::string Form::getName() const { return (_name); }
bool Form::getIsSigned() const { return (_is_signed); }
int  Form::getGradeToSign() const { return (_grade_to_sign); }
int  Form::getGradeToExcute() const { return (_grade_to_exec); }

// Methods
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_to_sign)
	{
		if (_is_signed)
			throw Form::AlreadySignedFormException();
		_is_signed = true;
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
