/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:39:32 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/26 19:46:43 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name); 
        ~ScavTrap();
        void attack(std::string const & target);
        void guardGate();
    private:
        bool _guardMode;
};

#endif