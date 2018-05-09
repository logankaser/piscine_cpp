/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:21:33 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 16:11:33 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string n, std::string t) : name(n), type(t) {}

Zombie::~Zombie(void)
{
	std::cout << "The Zombie " << name << " is no more" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout
		<< "Name: " << name << "; "
		<< "Type: " << type << "; Hungrryyy" << std::endl;
}
