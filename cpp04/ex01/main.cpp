/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:31:43 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/02 23:54:40 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j; // should not create a leak
        delete i;
    }
    {
        // Create and fill an array of Animals
        const int size = 30;
        const Animal* animals[size];

        for (int i = 0; i < size; i++) {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        // Make all the animals speak
        for (int i = 0; i < size; i++) {
            animals[i]->makeSound();
        }

        // Delete all the animals
        for (int i = 0; i < size; i++) {
            delete animals[i];
        }
    }
    {
        Cat* cat = new Cat();
        std::cout << "Cat's type: " << cat->getType() << std::endl;
        cat->makeSound();

        // print cat ideas
        for (int i = 0; i < 100; i++) {
            cat->getBrain()->getIdea();
        }
        delete cat;
    }
    return 0;
}