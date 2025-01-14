#include "Data.hpp"

Data(int nbr) : _nbr(nbr) {}

~Data() {}

Data(const Data& other) {

}
Data& operator=(const Data& other){

}

int getInt(void) const { return this->_nbr; }