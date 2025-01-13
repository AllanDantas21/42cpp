/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:06:23 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 23:45:38 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	std::string str = "Allan";
	Zombie zom(str);
	Zombie *newZomb;

	zom.announce();
	newZomb = newZombie("Potato");
	newZomb->announce();
	randomChump("PotatoTwo");
	delete newZomb;
}