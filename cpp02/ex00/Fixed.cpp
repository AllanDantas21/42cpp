#include "Fixed.hpp"

const int Fixed::_RawBits = 8;

Fixed::Fixed() : _Value(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src)
		this->_Value = src.getRawBits();
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_Value);
}

void Fixed::setRawBits(int const raw) { _Value = raw; }