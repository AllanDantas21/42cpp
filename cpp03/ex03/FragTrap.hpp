/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:02:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/26 20:00:12 by aldantas         ###   ########.fr       */
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
        void highFivesGuys(void);
};

#endif