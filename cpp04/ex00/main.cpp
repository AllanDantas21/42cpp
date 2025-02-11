#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        std::cout << dog->getType() << " \n";
        std::cout << cat->getType() << " \n";
        cat->makeSound(); // will output the cat sound!
        dog->makeSound();
        animal->makeSound();

        delete animal;
        delete dog;
        delete cat;
    }
    std::cout << "\n";
    std::cout << "\n";
    {
        const WrongAnimal* animal = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();
        std::cout << cat->getType() << " \n";
        cat->makeSound();
        animal->makeSound();

        delete animal;
        delete cat;
    }
    std::cout << "\n";
    std::cout << "\n";
    {
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();
        const WrongCat* trueCat = new WrongCat();

        std::cout << "wrongAnimal getType : " << wrongAnimal->getType() << std::endl;
        std::cout << "wrongCat getType : " << wrongCat->getType() << std::endl;
        std::cout << "trueCat getType : " << trueCat->getType() << std::endl;

        wrongAnimal->makeSound();
        wrongCat->makeSound();
        trueCat->makeSound();

        delete wrongAnimal;
        delete wrongCat;
        delete trueCat;
    }

    return 0;
}