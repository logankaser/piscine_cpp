/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:41:23 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 18:38:03 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	std::string name;
	Weapon *weapon;
	public:
		HumanB(std::string n);
		void attack(void);
		void setWeapon(Weapon &w);
};

#endif
