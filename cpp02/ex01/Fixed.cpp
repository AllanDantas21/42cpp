/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:57 by aldantas          #+#    #+#             */
/*   Updated: 2025/01/12 23:55:06 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_RawBits = 8;

Fixed::Fixed() : _Value(0) { std::cout << "Default constructor called\n"; }
Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}
Fixed::Fixed(const int n)
{
	_Value = n << _RawBits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n)
{
	_Value = static_cast<int>(roundf(n * (1 << _RawBits)));
	std::cout << "Float constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_Value = src.getRawBits();
	std::cout << "Copy assignment operator called\n";
	return (*this);
}
std::ostream &operator<<(std::ostream &os, const Fixed &Fixed)
{
	os << Fixed.toFloat();
	return (os);
}


int Fixed::toInt(void) const { return (_Value >> _RawBits); }
float Fixed::toFloat(void) const { return (static_cast<float>(_Value) / (1 << _RawBits)); }
int Fixed::getRawBits(void) const { return (_Value); }
void Fixed::setRawBits(int const raw) { _Value = raw; }