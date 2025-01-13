#include "Intern.hpp"

Intern::Intern() {
    forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";
    std::cout << " * Intern default constructor * " << std::endl;
}

Intern::Intern(const Intern& intern) {
	std::cout << " * Intern Copy Constructor * " << std::endl;
	*this = intern;
}

Intern::~Intern() {
	std::cout << " * Intern Destructor * " << std::endl;
}

Intern& Intern::operator=(const Intern& value)
{
	if (this == &value)
		return (*this);
	for (int i = 0; i < 3; i++)
		forms[i] = value.forms[i];
	return (*this);
}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
    AForm* new_form = NULL;

    for (int i = 0; i < 3; i++) {
        if (forms[i] == form) {
            switch (i) {
                case 0:
                    new_form = new ShrubberyCreationForm(target);
                    break;
                case 1:
                    new_form = new RobotomyRequestForm(target);
                    break;
                case 2:
                    new_form = new PresidentialPardonForm(target);
                    break;
            }
            if (new_form) {
                std::cout << "Intern creates " << form << std::endl;
            }
            return new_form;
        }
    }
    std::cout << "No such form name" << std::endl;
    return NULL;
}
