/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:30:33 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/18 18:28:26 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
/* Constructors */
WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal default constructor called\n";
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src){
    std::cout << "WrongAnimal copy constructor called\n";
    *this = src;
}

/* Destructor */
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal " << this->type << " destroyed\n";
}

/* Overload */
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other){
    std::cout << "WrongAnimal assignation operator called\n";
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* Methods */
void WrongAnimal::makeSound() const{
    std::cout << "bla ble bli blo blu\n";
}

const std::string WrongAnimal::getType() const { return this->type; }
void WrongAnimal::setType(std::string type) { this->type = type; }
