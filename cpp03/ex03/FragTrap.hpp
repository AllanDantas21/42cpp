/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/26 19:48:15 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
    	FragTrap(std::string name); 
        ~FragTrap();
        void attack(std::string const & target);
        void highFivesGuys(void);
};

#endif