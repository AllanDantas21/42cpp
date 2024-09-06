/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:46 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:45:00 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
  protected:
	std::string  _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

  public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);
	int getLife(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};