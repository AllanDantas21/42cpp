#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
public:
    AAnimal();
    AAnimal(AAnimal const& src);
    virtual ~AAnimal();

    AAnimal& operator=(AAnimal const& other);
    const std::string getType(void) const;
    void setType(std::string type);
    virtual void makeSound(void) const = 0;

protected:
    std::string type;
};

#endif