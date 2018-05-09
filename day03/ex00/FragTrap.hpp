/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:35:33 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
class FragTrap
{
	private:
		unsigned hp;
		unsigned hp_max;
		unsigned en;
		unsigned en_max;
		unsigned lvl;
		std::string name;
		unsigned melee;
		unsigned ranged;
		unsigned armor;
	public:
		FragTrap(void);
		FragTrap(const std::string);
		FragTrap(const FragTrap&);
		~FragTrap(void);
		FragTrap& operator=(const FragTrap&);
		void meleeAttack(const std::string);
		void rangedAttack(const std::string);
		void takeDamage(unsigned);
		void beRepaired(unsigned);
		void vaulthunter_dot_exe(const std::string);
};
#endif
