/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:47:42 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 16:28:51 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form {

	private:
	Form(void);
	const std::string _name;
	const int _signGrade;
	const int _executeGrade;
	bool _signed;

	public:
	struct GradeTooHighException : public std::exception {
		const char* what(void) const throw();
	};
	struct GradeTooLowException : public std::exception {
		const char* what(void) const throw();
	};
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form&);
	Form& operator=(const Form&);
	~Form(void);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getSigned(void) const;
	void beSigned(Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
