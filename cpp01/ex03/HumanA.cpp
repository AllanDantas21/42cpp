#include <iostream>
#include "HumanA.hpp"

void HumanA::attack() {
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}