#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void processForm(Bureaucrat& signer, Bureaucrat& executor, AForm* form)
{
	std::cout << *form << std::endl;
	signer.signForm(*form);
	signer.executeForm(*form);
	executor.executeForm(*form);
	std::cout << *form << std::endl;
	delete form;
}

int main()
{
	try
	{
		// Create Bureaucrats with different grades
		Bureaucrat aldantas145("aldantas145", 145);
		Bureaucrat aldantas72("aldantas72", 72);
		Bureaucrat aldantas23("aldantas23", 23);
		Bureaucrat boss("Boss", 3);

		// Create an Intern
		Intern someRandomIntern;

		// Display initial Bureaucrat information
		std::cout << aldantas145 << "\n" << boss << std::endl;

		// Process ShrubberyCreationForm
		std::cout << "Processing ShrubberyCreationForm\n";
		processForm(aldantas145, boss, someRandomIntern.makeForm("shrubbery creation", "Aldantas"));
		std::cout << "*********************************\n";

		// Process RobotomyRequestForm
		std::cout << "Processing RobotomyRequestForm\n";
		processForm(aldantas72, boss, someRandomIntern.makeForm("robotomy request", "robotomy"));
		std::cout << "*********************************\n";

		// Process PresidentialPardonForm
		std::cout << "Processing PresidentialPardonForm\n";
		processForm(aldantas23, boss, someRandomIntern.makeForm("presidential pardon", "test"));
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
