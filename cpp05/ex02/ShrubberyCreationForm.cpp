#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("shrubbery creation", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& instance):
	AForm(instance), target(instance.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rvalue)
{
	if (this == &rvalue)
		return (*this);
	target = rvalue.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm]: destructed" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedFormException();
	if (this->getGradeToExec() < executer.getGrade())
		throw AForm::GradeTooLowException();

	std::string filename = target + "_shrubbery";
	std::ofstream ostrm(filename.c_str());
	if (!ostrm.is_open())
		throw ShrubberyCreationForm::FileCantOpenException();
	ostrm	<< "        v .   ._, |_  .,\n"
			<< "           `-._\\/  .  \\ /    |/_\n"
			<< "               \\\\  _\\, y | \\\\//\n"
			<< "         _\\_.___\\\\, \\\\/ -.\\||\n"
			<< "           `7-,--.`._||  / / ,\n"
			<< "           /'     `-. `./ / |/_.'\n"
			<< "                     |    |//\n"
			<< "                     |_    /\n"
			<< "                     |-   |\n"
			<< "                     |   =|\n"
			<< "                     |    |\n"
			<< "--------------------/ ,  . \\--------._\n" << std::endl;
	ostrm.close();
}

const char* ShrubberyCreationForm::FileCantOpenException::what() const throw()
{
	const char* reason = "Can't open output file";
	return (reason);
}