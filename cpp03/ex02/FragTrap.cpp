#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void){
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
    std::cout << "FragTrap parameter constructor called\n";
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap default destructor called\n";
}

void FragTrap::highFivesGuys(){
    std::cout << "High five, guys!\n";
}