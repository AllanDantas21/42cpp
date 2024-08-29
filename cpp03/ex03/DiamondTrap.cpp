/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:41 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/28 21:19:48 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() , FragTrap(), ScavTrap() {
    std::cout << "[DiamondTrap]" << " default constructor called\n";
    this->_name = "Default Diamond";
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "[DiamondTrap]" << " " << name << " created\n";
    this->_name = name;
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout <<  "[DiamondTrap]" << " " << this->getName() << " destroyed\n";
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "[DiamondTrap]" <<  " " << this->_name << " is " << ClapTrap::_name << '\n';
}

