/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:45:15 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 16:32:12 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b("Bob", 149);
	try
	{
		b.decGrade();
		b.decGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat g("God", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << b << std::endl;
}
