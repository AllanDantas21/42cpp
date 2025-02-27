#include "AAnimal.hpp"
/* Construtors */
AAnimal::AAnimal(){
    std::cout << "AAnimal default constructor called\n";
    this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& src){
    std::cout << "AAnimal copy constructor called\n";
    *this = src;
}

/* Destrutor*/
AAnimal::~AAnimal(){
    std::cout << "AAnimal " << this->type << " destroyed\n";
}

/* Overload */
AAnimal& AAnimal::operator=(AAnimal const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* Metodos */
void AAnimal::makeSound() const{
    std::cout << "Spooklk\n";
}

/* Getters e Setters */
const std::string AAnimal::getType() const { return this->type; }
void AAnimal::setType(std::string type) { this->type = type; }
