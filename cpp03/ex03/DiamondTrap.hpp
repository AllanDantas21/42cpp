/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:37 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/26 19:56:41 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
    void whoAmI(void);
    using ScavTrap::attack;
     
private:
    std::string _name;
    
};

#endif