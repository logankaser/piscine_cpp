/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:59:45 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/11 16:18:10 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const int i)
{
	_value = i << _point;
}

Fixed::Fixed(const double f)
{
	_value = round(f * (1 << _point));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed &r)
{
	*this = r;
}

Fixed	&Fixed::operator=(Fixed const &r)
{
	if (this != &r)
		_value = r.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream& strm, const Fixed &f)
{
	strm << f.toFloat();
	return strm;
}

bool Fixed::operator>(const Fixed &f)
{
	return toFloat() > f.toFloat();
}

bool Fixed::operator<(const Fixed &f)
{
	return toFloat() < f.toFloat();
}

bool Fixed::operator>=(const Fixed &f)
{
	return toFloat() >= f.toFloat();
}

bool Fixed::operator<=(const Fixed &f)
{
	return toFloat() <= f.toFloat();
}

bool Fixed::operator==(const Fixed &f)
{
	return toFloat() == f.toFloat();
}

bool Fixed::operator!=(const Fixed &f)
{
	return toFloat() != f.toFloat();
}

Fixed Fixed::operator+(const Fixed &f)
{
	return Fixed(_value + f.getRawBits());
}

Fixed Fixed::operator-(const Fixed &f)
{
	return Fixed(_value - f.getRawBits());
}

Fixed Fixed::operator*(const Fixed &f)
{
	return Fixed(toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f)
{
	if (!f.getRawBits())
	{
		std::cout << "ERROR: Divison by zero" << std::endl;
		exit(1);
	}
	return Fixed(toFloat() / f.toFloat());
}

Fixed& Fixed::operator--(void)
{
	--_value;
	return *this;
}

Fixed Fixed::operator--(const int i)
{
	Fixed copy(*this);
	_value -= 1 + i;
	return copy;
}

Fixed& Fixed::operator++(void)
{
	++_value;
	return *this;
}

Fixed Fixed::operator++(const int i)
{
	Fixed copy(*this);
	_value += 1 + i;
	return copy;
}

int		Fixed::getRawBits(void) const
{
	return _value;
}

void	Fixed::setRawBits(int const v)
{
	_value = v;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _point));
}

int		Fixed::toInt(void) const
{
	return (_value >> _point);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? b : a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? b : a);
}
