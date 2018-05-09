/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:47:42 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/15 18:51:14 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Intern {
	public:
	Intern(void);
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern(void);
	Form* makeForm(std::string, std::string) const;
};

#endif
