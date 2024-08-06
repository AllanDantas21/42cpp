/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:08:40 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/06 00:18:18 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    public:
        Zombie( std::string name);
        ~Zombie();

        Zombie* newZombie( std::string name);
        void	randomChump( std::string name);
	private:
		void	announce();
		str		name;
};

#endif