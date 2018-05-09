/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:24:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 17:57:28 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
Form(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
	operator=(other);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->setTarget(other.getTarget());
	return *this;
}

void RobotomyRequestForm::action(void) const
{
	std::srand(std::time(0));
	std::string str = (std::rand() % 10) >= 5 ? " has been robotomized." : " robotomy failed.";
	std::cout
		<< "* Drilling Noises *" << std::endl
		<< this->getTarget() << str
		<< std::endl;
}
