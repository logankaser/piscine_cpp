/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 14:37:56 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"

#ifndef SORCERER_H
# define SORCERER_H
class Sorcerer
{
	private:
		std::string name;
		std::string title;
		Sorcerer(void);
	public:
		Sorcerer(std::string, std::string);
		Sorcerer(const Sorcerer&);
		~Sorcerer(void);
		Sorcerer& operator=(const Sorcerer&);
		std::string getName(void) const;
		std::string getTitle(void) const;
		void polymorph(const Victim&) const;
};

std::ostream& operator<<(std::ostream&, const Sorcerer&);

#endif
