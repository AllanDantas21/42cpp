/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 01:45:38 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/02 23:01:21 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;

	try {
		Donald = new Bureaucrat("Donald", 5);
		Donald->increaseGrade();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Joe = new Bureaucrat(*Donald);
	std::cout << *Donald << std::endl;
	std::cout << *Joe << std::endl;
	delete Donald;
}
