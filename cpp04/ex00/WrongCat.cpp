#include "WrongCat.hpp"

/* Constructors */
WrongCat::WrongCat(){
    std::cout << "WrongCat default constructor called\n";
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal() {
    std::cout << "WrongCat copy constructor called\n";
    *this = src;
}

/* Destructor */
WrongCat::~WrongCat(){
    std::cout << "WrongCat " << this->type << " destroyed\n";
}

/* Overload */
WrongCat& WrongCat::operator=(WrongCat const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}

/* Methods*/
void WrongCat::makeSound() const{
    std::cout << "Mewooooof" << std::endl;
}
