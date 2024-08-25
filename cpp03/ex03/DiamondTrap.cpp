/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:41 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/25 18:15:41 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap()
    , FragTrap()
    , ScavTrap()

{
    std::cout << CYAN << "[DiamondTrap]" << RESET << " default constructor called" << std::endl;
    this->_name = "Default Diamond";
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << CYAN << "[DiamondTrap]" << RESET << " " << name << " created" << std::endl;
    this->_name = name;
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
    std::cout << CYAN << "[DiamondTrap]" << RESET << " copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << CYAN << "[DiamondTrap]" << RESET << " " << this->getName() << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << CYAN << "[DiamondTrap]" << RESET << " " << this->_name << " is " << ClapTrap::_name << std::endl;
}

