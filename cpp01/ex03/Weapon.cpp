#include <iostream>
#include "Weapon.hpp"

const std::string &Weapon::getType() const {
    return (_type);
};

void Weapon::setType(const std::string &type) {
    _type = type;
};