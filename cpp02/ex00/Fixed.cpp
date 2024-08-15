/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:57 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/15 16:57:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_RawBits = 8;

Fixed::Fixed() : _Value(0){
    std::cout << "Default constructor called\n";
};

Fixed::Fixed( const Fixed& copy ){
    std::cout << "Copy constructor called\n";
    *this = copy;
};

Fixed &Fixed::operator =(const Fixed &src){
    if (this != &src)
        this->_Value = src.getRawBits();
    std::cout << "Copy assignment operator called\n";
    return *this;
};

Fixed::~Fixed(){
    std::cout << "Destructor called\n";

};

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called\n";
    return (_Value);
}

void Fixed::setRawBits( int const raw ) {
    _Value = raw;
};