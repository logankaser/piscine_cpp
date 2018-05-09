/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 14:55:20 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef VICTIM_H
# define VICTIM_H
class Victim
{
	protected:
		std::string name;
		std::string title;
		Victim(void);
	public:
		Victim(std::string);
		Victim(const Victim&);
		~Victim(void);
		Victim& operator=(const Victim&);
		std::string getName(void) const;
		virtual void getPolymorphed(void) const;
};

std::ostream& operator<<(std::ostream&, const Victim&);

#endif
