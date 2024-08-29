/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:37:38 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/28 21:44:18 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
/* Construtor*/
Animal::Animal()
{
    std::cout << "[Animal] default constructor called" << std::endl;
    this->type = "Animal";
}
/* Destrutor*/
Animal::~Animal()
{
    std::cout << "[Animal] " << this->type << " destroyed" << std::endl;
}

/* Metodos */
void Animal::makeSound() const
{
    std::cout << "Spooklk" << std::endl;
}

/* Getters e Setters */
const std::string Animal::getType() const
{
    return this->type;
}

void Animal::setType(std::string type)
{
    this->type = type;
}
