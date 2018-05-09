/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:59:45 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/11 14:58:06 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &r)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &r)
		_value = r.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &r)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = r;
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const v)
{
	_value = v;
}
