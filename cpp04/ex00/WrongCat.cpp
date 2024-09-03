/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:30:50 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 22:42:53 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* Constructors */
WrongCat::WrongCat(){
    std::cout << "WrongCat default constructor called\n";
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal() {
    std::cout << "WrongCat copy constructor called\n";
    *this = src;
}

/* Destructor */
WrongCat::~WrongCat(){
    std::cout << "WrongCat " << this->type << " destroyed\n";
}

/* Overload */
WrongCat& WrongCat::operator=(WrongCat const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* Methods*/
void WrongCat::makeSound() const{
    std::cout << "Mewooooof" << std::endl;
}
