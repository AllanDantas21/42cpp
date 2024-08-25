/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:46 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/25 18:16:47 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
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
	ClapTrap(std::string name);
	~ClapTrap();
	int getLife(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
    unsigned int getHP(void) const;
    unsigned int getEP(void) const;
    unsigned int getAD(void) const;
    void setHP(unsigned int amount);
    void setEP(unsigned int amount);
    void setAD(unsigned int amount);
    void setName(std::string name);
};
#endif