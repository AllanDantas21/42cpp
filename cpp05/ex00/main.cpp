/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:38 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 16:42:24 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat intern("intern", 145);
		Bureaucrat boss("Boss", 3);

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
		std::cout << intern << "\n" << boss << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}