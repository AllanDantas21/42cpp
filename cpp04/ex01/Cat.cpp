/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/17 12:01:27 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Construtors */
Cat::Cat(){
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src): Animal(){
    std::cout << "Cat copy constructor called\n";
    this->_brain = new Brain(*src._brain);
    this->type = src.type;
}

/* Destructor */
Cat::~Cat(){
    std::cout << "Cat " << this->type << " destroyed\n";
    delete this->_brain;
}

/* Overload */
Cat& Cat::operator=(Cat const& other){
    if (this != &other) {
        this->type = other.getType();
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

/* Methods */
void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->_brain;
}