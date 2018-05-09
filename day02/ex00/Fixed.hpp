/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:21:09 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/11 18:08:27 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int _value;
		static const unsigned _frac = 8;
	public:
		Fixed(void);
		Fixed(const Fixed&);
		Fixed &operator=(Fixed const&);
		~Fixed(void);
		int	getRawBits(void) const;
		void setRawBits(int const);
};
#endif
