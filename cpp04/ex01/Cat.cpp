#include "Cat.hpp"

/* Construtors */
Cat::Cat(){
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Brain const& brain) {
    std::cout << "Cat parameterized constructor called\n";
    this->type = "Cat";
    this->_brain = new Brain(brain);
}

Cat::Cat(const Cat& src) : Animal(), _brain(new Brain(*src._brain)) {
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
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

/* Methods */
void Cat::makeSound() const{
    std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const { return this->_brain; }