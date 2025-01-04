/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:38 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/04 02:09:09 by aldantas         ###   ########.fr       */
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
				intern.decreaseGrade();
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
				boss.increaseGrade();
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