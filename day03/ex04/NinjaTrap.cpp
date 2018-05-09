/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:51:42 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap(60, 60, 120, 120, 1, "Ninjatrap", 60, 5, 0)
{
	std::srand(std::time(0));
	std::cout << "N1NJ4-TP created, name defaulting to \"Ninjatrap\"" << std::endl;
}

NinjaTrap::NinjaTrap(std::string n) : ClapTrap(60, 60, 120, 120, 1, n, 60, 5, 0)
{
	std::srand(std::time(0));
	std::cout << "N1NJ4-TP created, named " << name << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "N1NJ4-TP " << name << " destroyed!" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &other)
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

void NinjaTrap::ninjaShoebox(const FragTrap&)
{
	std::cout << name << " snuck up on a FragTrap and ninja'ed it." << std::endl;
}

void NinjaTrap::ninjaShoebox(const ScavTrap&)
{
	std::cout << name << " threw a Kunai at the unsuspecting ScavTrap" << std::endl;
}

void NinjaTrap::ninjaShoebox(const NinjaTrap&)
{
	std::cout << name << " fought a Ninja fight!" << std::endl;
}
