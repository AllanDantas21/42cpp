#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    *this = other;
    std::cout << "Copy Constructor -> " << _name << "\n";
}

ScavTrap::ScavTrap(std::string name){
    std::cout << "ScavTrap parameter constructor called\n";
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardMode = false;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap default destructor called\n";
}

void ScavTrap::guardGate(void){
	if(this->_guardMode)
    {
        std::cout << "GuardMode on\n";
        return ;
    }
    this->_guardMode = true;
    std::cout << "GuardMode Activate\n";
}

void ScavTrap::attack(const std::string &target){
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have any hit points or energy points left.\n";
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}