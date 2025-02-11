#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl;
	try
	{
		Bureaucrat intern("intern", 3);
		Bureaucrat boss("Boss", 147);

		std::cout << "****** increase grade ******" << std::endl;
		while (true)
		{
			try
			{
				intern.increaseGrade();
				std::cout << intern << std::endl;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				break;
			}
		}
		std::cout << "****************************" << std::endl << std::endl;
		std::cout << "****** decrease grade ******" << std::endl;
		while (true)
		{
			try
			{
				boss.decreaseGrade();
				std::cout << boss << std::endl;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				break;
			}
		}
		std::cout << "****************************" << std::endl << std::endl;
		std::cout << intern << "\n" << boss << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}