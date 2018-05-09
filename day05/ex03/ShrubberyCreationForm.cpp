/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:24:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 17:49:48 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
Form(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
	operator=(other);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->setTarget(other.getTarget());
	return *this;
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream out(this->getTarget() + "_shrubbery");
	out
		<< "    .o.'." << std::endl
		<< "   .'.'o'." << std::endl
		<< "  o'.o.'.o." << std::endl
		<< " .'.o.'.'.o." << std::endl
		<< ".o.'.o.'.o.'." << std::endl
		<< "   [_____]" << std::endl
		<< "    \\___/" << std::endl;
	out.close();
}
