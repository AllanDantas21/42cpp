/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:06:23 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/13 15:31:56 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 5;

	Zombie *z = zombieHorde(N, "allan");
	for (int i = 0; i < N; i++)
		z->announce();
	delete[] z;
}
