/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:42 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/25 18:16:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap contructor called\n";
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10) {
    std::cout << "Constructor ClapTrap -> " + _name << "\n";
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor ClapTrap -> " + _name << "\n";
}

void ClapTrap::attack(const std::string &target){
    if (_energyPoints == 0)
        return ;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_energyPoints == 0)
        return ;
    std::cout << _name << " take damage: " << amount << "\n";
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_energyPoints == 0)
        return ;
    std::cout << _name << " has been repaired: " << amount << "\n";
    _hitPoints += amount;
}

std::string ClapTrap::getName(void) const
{
    return _name;
}

unsigned int ClapTrap::getHP(void) const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEP(void) const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAD(void) const
{
    return _attackDamage;
}

void ClapTrap::setHP(unsigned int amount)
{
    _hitPoints = amount;
}

void ClapTrap::setEP(unsigned int amount)
{
    _energyPoints = amount;
}

void ClapTrap::setAD(unsigned int amount)
{
    _attackDamage = amount;
}

