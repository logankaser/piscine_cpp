/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 17:22:18 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef RADSCORPION_H
# define RADSCORPION_H

class RadScorpion
{
	private:
		RadScorpion(void);
	protected:
		int	hp;
		std::string type;
	public:
		RadScorpion(int hp, const std::string&);
		RadScorpion(const RadScorpion&);
		virtual ~RadScorpion(void);
		RadScorpion& operator=(const RadScorpion&);
		std::string getType(void) const;
		int getHP(void) const;
		virtual void takeDamage(int);
};

#endif
