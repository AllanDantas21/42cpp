/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:51 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/18 18:25:30 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void){
    std::cout << "FragTrap default constructor called\n";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name){
    std::cout << "FragTrap parameter constructor called\n";
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}
FragTrap::~FragTrap(){
    std::cout << "FragTrap default destructor called\n";
}

void FragTrap::highFivesGuys(){
    std::cout << "High five, guys!\n";
}

unsigned int FragTrap::getHP(void) const { return _hitPoints; }
unsigned int FragTrap::getEP(void) const { return _energyPoints; }
unsigned int FragTrap::getAD(void) const { return _attackDamage; }