/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:08:12 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 23:46:01 by aldantas         ###   ########.fr       */
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