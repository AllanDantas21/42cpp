#include "Cat.hpp"

/* Construtors */
Cat::Cat(){
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src): AAnimal(){
    std::cout << "Cat copy constructor called\n";
    *this = src;
}

/* Destructor */
Cat::~Cat(){
    std::cout << "Cat " << this->type << " destroyed\n";
     delete this->_brain;
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

Brain* Cat::getBrain() const
{
    return this->_brain;
}