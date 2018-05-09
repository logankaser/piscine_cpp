/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:45:15 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 18:58:05 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
	ShrubberyCreationForm sf("bob");
	t.executeForm(sf);
	t.signForm(sf);
	t.executeForm(sf);
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	t.signForm(*rrf);
	t.executeForm(*rrf);
}
