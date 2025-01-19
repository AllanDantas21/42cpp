/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:02:32 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/18 18:30:35 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(Dog const& src);
        Dog(Brain const& brain);
        virtual ~Dog();

        Dog& operator=(Dog const& rhs);
        virtual void makeSound(void) const;
        Brain* getBrain(void) const;
};
#endif