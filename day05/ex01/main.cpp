/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:45:15 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 16:29:45 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	Form f("A Form", 42, 42);
	std::cout << "Form Created. " << f << std::endl;
	Bureaucrat t("Tony", 21);
	t.signForm(f);
	std::cout << f << std::endl;
	try
	{
		Form wont_work("Dumb Form", 0, 42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}
