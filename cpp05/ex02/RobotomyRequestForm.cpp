#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("robotomy request", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& instance):
	AForm(instance), target(instance.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& value)
{
	if (this == &value)
		return (*this);
	target = value.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: destructed" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& exec) const
{
	const std::string RED = "\033[0;31m";
	const std::string GREEN = "\033[0;32m";
	const std::string BLUE = "\033[0;34m";
	const std::string RESET = "\033[0m";

	if (!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if (this->getGradeToExec() < exec.getGrade())
		throw AForm::GradeTooLowException();

	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << GREEN << target << " successfully robotomized" << RESET << std::endl;
	else
		std::cout << RED << target << " robomize failed" << RESET << std::endl;
}