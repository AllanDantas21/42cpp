/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:37 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/18 18:23:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    ~DiamondTrap();
    void whoAmI(void);

    unsigned int getHP(void) const;
    unsigned int getEP(void) const;
    unsigned int getAD(void) const;
};

#endif