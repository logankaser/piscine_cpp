/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:41:51 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
class ScavTrap
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
		ScavTrap(void);
		ScavTrap(const std::string);
		ScavTrap(const ScavTrap&);
		~ScavTrap(void);
		ScavTrap& operator=(const ScavTrap&);
		void meleeAttack(const std::string);
		void rangedAttack(const std::string);
		void takeDamage(unsigned);
		void beRepaired(unsigned);
		void challengeNewcomer(std::string);
};
#endif
