/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:37 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/25 18:15:42 by aldantas         ###   ########.fr       */
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
    DiamondTrap(DiamondTrap const& src);
    ~DiamondTrap();
    void whoAmI(void);

private:
    std::string _name;
};

#endif