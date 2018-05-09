/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:24:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 18:54:50 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}
Intern::~Intern(void) {}
Intern::Intern(const Intern &other) {operator=(other);}
Intern& Intern::operator=(const Intern &) {return *this;}

Form *Intern::makeForm(std::string form, std::string target) const
{
	if (form == "ShrubberyCreationForm")
	{
		std::cout << "Intern creates " << form << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (form == "RobotomyRequestForm")
	{
		std::cout << "Intern creates " << form << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (form == "PresidentialPardonForm")
	{
		std::cout << "Intern creates " << form << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
		std::cout << "Itern could not find a form by that name. ???" << form << std::endl;
	return (0);
}
