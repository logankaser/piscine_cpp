/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:34:21 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/11 13:36:48 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "a = 42" << std::endl << (a = 42) << std::endl;
	std::cout << "++a" << std::endl << (++a) << std::endl;
	std::cout << "--a" << std::endl << (--a) << std::endl;
	std::cout << "a + 2" << std::endl << (a + 2) << std::endl;
	std::cout << "a - 2" << std::endl << (a - 2) << std::endl;
	std::cout << "a * 2" << std::endl << (a * 2) << std::endl;
	std::cout << "a / 2" << std::endl << (a / 2) << std::endl;
	std::cout << "a / 0" << std::endl << (a / 0) << std::endl;
	return 0;
}
