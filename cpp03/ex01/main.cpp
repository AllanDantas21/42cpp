/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:20 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/21 11:44:25 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.cpp"

int main(){
    ClapTrap a("allan");
    ScavTrap b("dantas");

    a.attack("dantas");
    a.takeDamage(5);
    b.attack("allan");
    b.guardGate();
    std::cout << "current Life: " << a.getLife() << "\n";
}