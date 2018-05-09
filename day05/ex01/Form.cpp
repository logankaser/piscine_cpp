/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:24:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 16:18:34 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _signGrade(150), _executeGrade(150) {}
Form::Form(std::string name, int sg, int eg) :
_name(name), _signGrade(sg), _executeGrade(eg), _signed(false)
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
}

Form::~Form(void) {}

Form::Form(const Form &other) :
_name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	operator=(other);
}

Form& Form::operator=(const Form &other)
{
    if (this == &other)
        return *this;
    _signed = other.getSigned();
    return *this;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException\n";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException\n";
}


std::string Form::getName(void) const {return _name;}
int Form::getSignGrade(void) const {return _executeGrade;}
int Form::getExecuteGrade(void) const {return _signGrade;}
bool Form::getSigned(void) const {return _signed;}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

std::ostream& operator<<(std::ostream& strm, const Form &f)
{
    strm
		<< "Form: " << f.getName() << "; "
		<< "Signed?: " << f.getSigned() << "; "
		<< "SignGrade: " << f.getSignGrade() << "; "
		<< "ExecuteGrade: " << f.getExecuteGrade() << "; ";
    return strm;
}
