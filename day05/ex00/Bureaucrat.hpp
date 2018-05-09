/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:47:42 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 16:31:30 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <stdexcept>
#include <iostream>

class Bureaucrat {

	private:
	std::string const _name;
	int _grade;

	public:
	struct GradeTooHighException : public std::exception {
		const char* what(void) const throw();
	};
	struct GradeTooLowException : public std::exception {
		const char* what(void) const throw();
	};
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat(void);

	std::string getName(void) const;
	int getGrade(void) const;
	void incGrade(void);
	void decGrade(void);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
