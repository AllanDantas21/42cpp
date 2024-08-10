/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:06:23 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/10 18:40:32 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string str = "allan";
	Zombie zom(str);
	Zombie *newZomb;

	zom.announce();
	newZomb = newZombie("batata");
	newZomb->announce();
	randomChump("batata2");
	delete newZomb;
}