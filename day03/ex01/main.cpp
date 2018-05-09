/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:06:47 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/11 16:59:59 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap def;
	FragTrap not_def("Clappy");
	ScavTrap serena("Serena");
	def.vaulthunter_dot_exe("???");
	not_def.vaulthunter_dot_exe("???");
	not_def.meleeAttack("target");
	not_def.rangedAttack("target");
	not_def.takeDamage(30);
	not_def.vaulthunter_dot_exe("???");
	not_def.vaulthunter_dot_exe("???");
	not_def.vaulthunter_dot_exe("???");
	not_def.vaulthunter_dot_exe("???");
	not_def.vaulthunter_dot_exe("???");
	not_def.beRepaired(100);
	not_def.vaulthunter_dot_exe("???");
	serena.challengeNewcomer("vault hunter");
}
