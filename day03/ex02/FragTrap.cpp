/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:45:29 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(100, 100, 100, 100, 1, "Fragtrap", 30, 20, 5)
{
	std::srand(std::time(0));
	std::cout << "FRAG-TP created, name defaulting to \"Fragtrap\"" << std::endl;
}

FragTrap::FragTrap(std::string n) : ClapTrap(100, 100, 100, 100, 1, n, 30, 20, 5)
{
	std::srand(std::time(0));
	std::cout << "FR4G-TP created, named " << name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << name << " destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

FragTrap& FragTrap::operator=(const FragTrap &other)
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

void FragTrap::vaulthunter_dot_exe(const std::string target)
{
	static std::string attacks[] = {
		"sneak", "lunge",
		"extra sneaky", "super",
		"quick", "not quick"
	};
	if (en < 25)
	{
		std::cout << "Not enough energy!" << std::endl;
		return;
	}
	en -= 25;
	std::cout
		<< name << " used " << attacks[std::rand() % 6]
		<< " attack! on " << target << std::endl;
}
