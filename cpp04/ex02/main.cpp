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