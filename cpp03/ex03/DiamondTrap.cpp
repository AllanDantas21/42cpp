#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
    std::cout << "[DiamondTrap]" << " default constructor called\n";
    this->_name = "Default Diamond";
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::getHP();
    this->_energyPoints = ScavTrap::getEP();
    this->_attackDamage = FragTrap::getAD();
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap()
{
    std::cout << "[DiamondTrap]" << " " << name << " created\n";
    this->_name = name;
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout <<  "[DiamondTrap]" << " " << this->getName() << " destroyed\n";
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "[DiamondTrap]" <<  " " << this->_name << " is " << ClapTrap::_name << '\n';
}

unsigned int DiamondTrap::getHP(void) const { return _hitPoints; }
unsigned int DiamondTrap::getEP(void) const { return _energyPoints; }
unsigned int DiamondTrap::getAD(void) const { return _attackDamage; }

