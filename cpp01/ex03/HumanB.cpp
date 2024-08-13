/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:21:53 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/13 19:06:05 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    _weapon = 0;
};

void HumanB::attack() {
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
};

void HumanB::setWeapon( Weapon &weapon) {
    _weapon = &weapon;
};