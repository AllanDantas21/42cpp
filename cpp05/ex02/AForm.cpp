#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int grade_to_sign, const int grade_to_exec, const std::string& target)
	: name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec), target(target) {
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& instance)
	: name(instance.name), is_signed(instance.is_signed), grade_to_sign(instance.grade_to_sign), grade_to_exec(instance.grade_to_exec), target(instance.target) {}

AForm& AForm::operator=(const AForm& rvalue) {
	if (this == &rvalue)
		return *this;
	this->is_signed = rvalue.is_signed;
	this->target = rvalue.target;
	return *this;
}

AForm::~AForm(){}

const std::string AForm::getName() const{
	return name;
}

bool AForm::isSigned() const{
	return is_signed;
}

int AForm::getGradeToSign() const{
	return grade_to_sign;
}

int AForm::getGradeToExecute() const{
	return grade_to_exec;
}

const std::string& AForm::getTarget() const{
	return target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->grade_to_sign)
		throw AForm::GradeTooLowException();
	if (this->is_signed)
		throw AForm::AlreadySignedFormException();
	this->is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& rvalue) {
	os << "Form " << rvalue.getName() << ", signed: " << rvalue.isSigned()
	   << ", grade to sign: " << rvalue.getGradeToSign()
	   << ", grade to execute: " << rvalue.getGradeToExecute();
	return os;
}
