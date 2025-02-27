#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat intern("aldantas", 145);
		Bureaucrat boss("Boss", 3);
		Form lunch_menu("lunch menu", 148, 149);
		Form launch_bomb("launch bomb", 10, 10);

		std::cout << intern << "\n" << boss << "\n" << lunch_menu << "\n" << launch_bomb << std::endl;
		intern.signForm(lunch_menu);
		std::cout << lunch_menu << std::endl;
		intern.signForm(launch_bomb);
		std::cout << launch_bomb << std::endl;
		boss.signForm(launch_bomb);
		std::cout << launch_bomb << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}