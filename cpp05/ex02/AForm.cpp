#include "AForm.hpp"

// Constructors
AForm::AForm(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec):
	_name(_name), _is_signed(false), _grade_to_sign(_grade_to_sign), _grade_to_exec(_grade_to_exec)
{
	if (_grade_to_exec > 150 || _grade_to_sign > 150)
		throw AForm::GradeTooHighException();
	if (_grade_to_exec < 1 || _grade_to_sign < 1)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy):
	_name(copy._name), _is_signed(copy._is_signed), _grade_to_sign(copy._grade_to_sign), _grade_to_exec(copy._grade_to_exec)
{}

// Assignment operator
AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return (*this);
	_is_signed = other._is_signed;
	return (*this);
}

// Destructor
AForm::~AForm()
{
	std::cout << "[AForm]: " << _name << " destructed" << std::endl;
}

// Getters
const std::string AForm::getName() const { return (_name); }
bool AForm::getIsSigned() const { return (_is_signed); }
int AForm::getGradeToSign() const { return (_grade_to_sign); }
int AForm::getGradeToExec() const { return (_grade_to_exec); }

// Methods
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_to_sign)
	{
		if (_is_signed)
			throw AForm::AlreadySignedFormException();
		_is_signed = true;
	}
	else
		throw AForm::GradeTooLowException();
}

// Overload operator
std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	const std::string is_signed_str = other.getIsSigned() ? "true" : "false";
	os 	<< "===== AForm ["<< other.getName() << "]=====\n"
		<< "Signed: " << is_signed_str << "\n"
		<< "Grade to sign: " << other.getGradeToSign() << "\n"
		<< "Grade to execute: " << other.getGradeToExec()
		<< "\n====================";
	return os;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high for form"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low for form"; }
const char* AForm::AlreadySignedFormException::what() const throw() { return "AForm is already signed"; }
const char* AForm::NotSignedFormException::what() const throw() { return "AForm wasn't signed yet"; }
