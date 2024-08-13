/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:49:26 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/13 15:31:46 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* Horde = new Zombie[N]; 
    
	  for (int i = 0; i < N; i++) {
        new (&Horde[i]) Zombie(name);
    }
    return Horde; 
}