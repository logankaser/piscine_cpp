/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:59:45 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 12:13:17 by lkaser           ###   ########.fr       */
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
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &r)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = r;
}

Fixed	&Fixed::operator=(Fixed const &r)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &r)
		_value = r.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream& strm, const Fixed &f)
{
	strm << f.toFloat();
	return strm;
}

int		Fixed::getRawBits(void) const
{
	return (_value);
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
