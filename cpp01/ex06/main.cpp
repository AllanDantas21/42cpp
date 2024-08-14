/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:59:26 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/14 11:05:53 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl harl;

	// std::cout << "Testing DEBUG level:\n";
	// harl.complain("DEBUG");
	// std::cout << "\nTesting INFO level:\n";
	// harl.complain("INFO");
	// std::cout << "\nTesting WARNING level:\n";
	// harl.complain("WARNING");
	std::cout << "\nTesting ERROR level:\n";
	harl.complain("ERROR");
	// std::cout << "\nTesting UNKNOWN level:\n";
	// harl.complain("UNKNOWN");
	return (0);
}