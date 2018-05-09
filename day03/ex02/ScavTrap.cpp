/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:46:01 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(100, 100, 50, 50, 1, "Scavtrap", 20, 15, 3)
{
	std::srand(std::time(0));
	std::cout << "D00R-TP created, name defaulting to \"Scavtrap\"" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(100, 100, 50, 50, 1, n, 20, 15, 3)
{
	std::srand(std::time(0));
	std::cout << "D00R-TP created, named " << name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "D00R-TP " << name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
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

void ScavTrap::challengeNewcomer(const std::string target)
{
	static std::string challenges[] = {
		"Stop!", "Halt Ruffian!",
		"You are under arrest!", "Cease foul bandit!",
	};
	std::cout
		<< name << " challened " << target << " with " 
		<< challenges[std::rand() % 4] << std::endl;
}
