/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:08:12 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/10 17:48:19 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "goodbye!" << '\n';
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << '\n';
}