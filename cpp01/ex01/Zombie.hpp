/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 00:08:40 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 23:46:38 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;
  public:
	Zombie() {};
	Zombie(std::string name) : _name(name){};
	~Zombie();
	void announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif