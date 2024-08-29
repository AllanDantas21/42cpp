/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:51 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/28 21:25:51 by aldantas         ###   ########.fr       */
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