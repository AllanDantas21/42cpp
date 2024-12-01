/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:02:32 by aldantas          #+#    #+#             */
/*   Updated: 2024/11/30 22:23:56 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {

public:
    Dog();
    Dog(Dog const& src);
    Dog(Brain const& brain);
    virtual ~Dog();

    Dog& operator=(Dog const& rhs);
    virtual void makeSound(void) const;
    Brain* getBrain(void) const;

private:
    Brain* _brain;
};

#endif