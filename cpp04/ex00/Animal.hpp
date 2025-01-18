/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:33:55 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/18 18:27:38 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(Animal const& src);
        virtual ~Animal();
    
        Animal& operator=(Animal const& other);
        const std::string getType(void) const;
        void setType(std::string type);
        virtual void makeSound(void) const;
};

#endif