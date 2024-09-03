/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:31:43 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/03 00:36:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{

    {
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();

        delete j;
        delete i;
    }
    {
        /* Animals array */
        const int size = 30;
        const AAnimal* animals[size];

        for (int i = 0; i < size; i++) {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        for (int i = 0; i < size; i++) {
            animals[i]->makeSound();
        }


        for (int i = 0; i < size; i++) {
            delete animals[i];
        }
    }
    {
        Cat* cat = new Cat();
        std::cout << "Cat's type: " << cat->getType() << std::endl;
        cat->makeSound();

        /* Print ideas */
        for (int i = 0; i < 100; i++) {
            cat->getBrain()->getIdea();
        }
        delete cat;
    }
    return 0;
}