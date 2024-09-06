/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:20 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/06 17:43:34 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
    ClapTrap a("allan");
    ClapTrap b = a;
    a.attack("dantas");
    a.takeDamage(5);
    std::cout << "current Life: " << a.getLife() << "\n";
}