/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:46:48 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 20:26:54 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	Human::meleeAttack(std::string const &target) 
{
	std::cout << "Human used sword on " << target << std::endl;
}

void	Human::rangedAttack(std::string const &target) 
{
	std::cout << "Human used bow on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const &target) 
{
	std::cout << "Human shouted intimidatingly at " << target << std::endl;
}

void	action(std::string const &action_name, std::string const &target)
{
	static std::lookup[] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};
	static void (Human::dispatch**)(std::string const &) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	unsigned i = 0;
	while (i < 3)
	{
		if (action_name == lookup[i])
		{
			dispatch[i](target);
			break;
		}
		++i;
	}
}
