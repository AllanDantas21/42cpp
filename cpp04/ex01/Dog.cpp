/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/11/30 22:23:55 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Constructors */
Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(Brain const& brain) {
    std::cout << "Dog parameterized constructor called\n";
    this->type = "Dog";
    this->_brain = new Brain(brain);
}

Dog::Dog(const Dog& src) : Animal(), _brain(new Brain(*src._brain)) {
    std::cout << "Dog copy constructor called\n";
    *this = src;
}

/* Destructor */
Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog " << this->type << " destroyed\n";
}

/* Overload */
Dog& Dog::operator=(Dog const& other) {
    if (this != &other) {
        this->type = other.getType();
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

/* Methods */
void Dog::makeSound() const {
    std::cout << "woof woof\n";
}

Brain* Dog::getBrain() const {
    return this->_brain;
}