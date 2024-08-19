/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:42 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/19 16:39:02 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10) {
    std::cout << "Constructor -> " + _name << "\n";
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor -> " + _name << "\n";
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

int ClapTrap::getLife(void){
    return (_hitPoints);
}

