/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:02:32 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 22:32:16 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {

public:
    Dog();
    Dog(Dog const& src);
    virtual ~Dog();

    Dog& operator=(Dog const& rhs);
    virtual void makeSound(void) const;
};

#endif 