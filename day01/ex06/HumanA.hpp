/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:41:23 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 18:35:09 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	std::string name;
	Weapon &weapon;
	public:
		HumanA(std::string n, Weapon &w);
		void attack(void);
};

#endif
