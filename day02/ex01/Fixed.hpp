/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:21:09 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 12:14:45 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int _value;
		static const unsigned _point = 8;
	public:
		Fixed(void);
		Fixed(const int);
		Fixed(const double);
		Fixed(const Fixed&);
		~Fixed(void);
		Fixed &operator=(Fixed const&);
		int	getRawBits(void) const;
		void setRawBits(int const);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
