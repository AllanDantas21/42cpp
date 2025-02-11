#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(Animal const& src);
    virtual ~Animal();

    Animal& operator=(Animal const& other);
    const std::string getType(void) const;
    void setType(std::string type);
    virtual void makeSound(void) const;

protected:
    std::string type;
};

#endif