/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 23:32:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Construtors */
Dog::Dog(){
    std::cout << "Dog default constructor called\n";
    this->type = "Dog";
}

Dog::Dog(const Dog& src): Animal() {
    std::cout << "Dog copy constructor called\n";
    *this = src;
}

/* Destructor */
Dog::~Dog(){
    std::cout << "Dog " << this->type << " destroyed\n";
}

/* Overload */
Dog& Dog::operator=(Dog const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* Methods */
void Dog::makeSound() const{
    std::cout << "woof woof\n";
}

Brain* Dog::getBrain() const
{
    return this->_brain;
}