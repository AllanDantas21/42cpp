#include "Data.hpp"

Data::Data(int nbr) : _nbr(nbr) {}

Data::~Data() {}

Data::Data(const Data& other) : _nbr(other._nbr) { }

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        this->_nbr = other._nbr;
    }
    return *this;
}

int Data::getInt(void) const { return this->_nbr; }