#include "Animal.hpp"
/* Construtors */
Animal::Animal(){
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& src){
    std::cout << "Animal copy constructor called\n";
    *this = src;
}

/* Destrutor*/
Animal::~Animal(){
    std::cout << "Animal " << this->type << " destroyed\n";
}

/* Overload */
Animal& Animal::operator=(Animal const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* Metodos */
void Animal::makeSound() const{
    std::cout << "Spooklk\n";
}

/* Getters e Setters */
const std::string Animal::getType() const { return this->type; }

void Animal::setType(std::string type) { this->type = type; }
