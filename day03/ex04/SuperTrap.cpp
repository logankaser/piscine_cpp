/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:55:54 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) :
ClapTrap(60, 60, 120, 120, 1, "Ninjatrap", 60, 5, 0), FragTrap(), NinjaTrap()
{
	std::srand(std::time(0));
	std::cout << "SUPER-TP created, name defaulting to \"Ninjatrap\"" << std::endl;
}

SuperTrap::SuperTrap(std::string n) :
ClapTrap(60, 60, 120, 120, 1, n, 60, 5, 0), FragTrap(n), NinjaTrap(n)
{
	std::srand(std::time(0));
	std::cout << "SUPER-TP created, named " << name << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUPER-TP " << name << " destroyed!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

SuperTrap& SuperTrap::operator=(const SuperTrap &other)
{
    std::cout << name << " assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    hp = other.hp;
    hp_max = other.hp_max;
    en = other.en;
    en_max = other.en_max;
    lvl = other.lvl;
    name = other.name;
    melee = other.melee;
    ranged = other.ranged;
    armor = other.armor;
    return *this;
}
