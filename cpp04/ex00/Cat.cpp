#include "Cat.hpp"

/* Construtors */
Cat::Cat(){
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
}

Cat::Cat(const Cat& src): Animal(){
    std::cout << "Cat copy constructor called\n";
    *this = src;
}

/* Destructor */
Cat::~Cat(){
    std::cout << "Cat " << this->type << " destroyed\n";
}

/* Overload */
Cat& Cat::operator=(Cat const& other){
    if (this != &other) {
        this->type = other.getType();
    }
    return *this;
}


/* Methods */
void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}
