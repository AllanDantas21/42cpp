#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap contructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    std::cout << "Copy Constructor -> " << _name << "\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20){
    std::cout << "Constructor ClapTrap-> " + _name << "\n";
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor ClapTrap -> " + _name << "\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "Copy Assignment Operator -> " << _name << "\n";
    return *this;
}

void ClapTrap::attack(const std::string &target){
    if (_energyPoints == 0)
        return ;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_energyPoints == 0)
        return ;
    std::cout << _name << " take damage: " << amount << "\n";
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_energyPoints == 0)
        return ;
    std::cout << _name << " has been repaired: " << amount << "\n";
    _hitPoints += amount;
}

int ClapTrap::getLife(void){ return (_hitPoints); }

