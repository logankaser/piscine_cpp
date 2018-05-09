/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:24:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 19:26:50 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	operator=(other);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;
    _grade = other.getGrade();
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException\n";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException\n";
}

std::string Bureaucrat::getName(void) const {return _name;}
int Bureaucrat::getGrade(void) const {return _grade;}

void Bureaucrat::incGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		--_grade;
}

void Bureaucrat::decGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		++_grade;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		std::cout << *this << " signs " << f << std::endl;
		f.beSigned(*this);
		std::cout << "Form is now signed"<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " cannot sign " << f << "because grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(Form &f)
{
	try
	{
		f.execute(*this);
		std::cout << *this << " executed " << f << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << *this << " cannot execute " << f << "because grade is too low." << std::endl;
	}
	catch (Form::FormNotSignedException &e)
	{
		std::cout << *this << " cannot execute " << f << "because form not signed" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& strm, const Bureaucrat &b)
{
    strm << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return strm;
}
