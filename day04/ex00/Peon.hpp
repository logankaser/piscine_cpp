/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 14:50:51 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"

#ifndef PEON_H
# define PEON_H
class Peon : public Victim
{
	private:
		Peon(void);
	public:
		Peon(std::string);
		Peon(const Peon&);
		~Peon(void);
		Peon& operator=(const Peon&);
		void getPolymorphed(void) const;
};

#endif
