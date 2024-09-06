/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:39:32 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:47:47 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap(std::string name); 
        ~ScavTrap();
        void attack(std::string const & target);
        void guardGate();
    private:
        bool _guardMode;
};