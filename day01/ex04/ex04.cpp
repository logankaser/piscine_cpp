/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:16:53 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 16:25:05 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brian = "HI THIS IS BRIAN";
	std::string *ptr = &brian;
	std::string &ref = brian;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
}
