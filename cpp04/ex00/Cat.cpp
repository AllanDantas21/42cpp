/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:01:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 23:24:20 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Construtors */
Cat::Cat(){
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
}

Cat::Cat(const Cat& src): Animal(){
    std::cout << "Cat copy constructor called\n";
    *this = src;
}

/* Destructor */
Cat::~Cat(){
    std::cout << "Cat " << this->type << " destroyed\n";
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
