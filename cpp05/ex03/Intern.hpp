#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
        std::string forms[3];
    public:
        Intern();
        Intern(const Intern& intern);
        Intern& operator=(const Intern& value);
        ~Intern();

        AForm* makeForm(const std::string& form, const std::string& target);
};

#endif