/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:39:27 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:24:28 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap parameter constructor called\n";
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_guardMode = false;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called\n";
}
void ScavTrap::guardGate(void)
{
	if(this->_guardMode)
    {
        std::cout << "GuardMode on\n";
        return ;
    }
    this->_guardMode = true;
    std::cout << "GuardMode Activate\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have any hit points or energy points left.\n";
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

unsigned int ScavTrap::getHP(void) const
{
    return _hitPoints;
}

unsigned int ScavTrap::getEP(void) const
{
    return _energyPoints;
}

unsigned int ScavTrap::getAD(void) const
{
    return _attackDamage;
}