#include "Bureaucrat.hpp"

// constructors & destructors
Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : _name(_name), _grade(_grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rvalue)
{
	if (this == &rvalue)
		return (*this);
	this->_grade = rvalue._grade;
	return (*this);
}

// getters
const std::string &Bureaucrat::getName() const { return _name; }
int	Bureaucrat::getGrade() const { return _grade; }

// methods
void	Bureaucrat::increaseGrade(){
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(){
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() { return "grade is too high!"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "grade is too low!"; }

// overloads
std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym) {
	o << rSym.getName() << ", bureaucrat grade : " << rSym.getGrade();
	return o;
}