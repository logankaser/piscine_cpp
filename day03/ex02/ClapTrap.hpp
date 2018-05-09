/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:42:39 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
class ClapTrap
{
	protected:
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
		ClapTrap(void);
		ClapTrap(unsigned, unsigned, unsigned, unsigned, unsigned, std::string, unsigned, unsigned, unsigned);
		ClapTrap(const ClapTrap&);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap&);
		void meleeAttack(const std::string);
		void rangedAttack(const std::string);
		void takeDamage(unsigned);
		void beRepaired(unsigned);
		void vaulthunter_dot_exe(const std::string);
};
#endif
