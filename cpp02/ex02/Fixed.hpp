/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:59 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/15 20:08:22 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int _Value;
	static const int _RawBits;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator=(const Fixed &copy);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &Fixed);