/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 22:42:55 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Construtors */
Cat::Cat(){
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& src): Animal(){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

/* Destructor */
Cat::~Cat(){
    std::cout << "Cat " << this->type << " destroyed" << std::endl;
}

/* Overload */
Cat& Cat::operator=(Cat const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}


/* Methods */
void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}
