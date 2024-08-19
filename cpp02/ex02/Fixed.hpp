/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:59 by aldantas          #+#    #+#             */
/*   Updated: 2024/08/19 10:42:55 by aldantas         ###   ########.fr       */
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

	Fixed &operator=(const Fixed &copy);
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

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

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

	int getRawBits(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &Fixed);