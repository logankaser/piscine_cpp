/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:39:33 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
hp(100), hp_max(100), en(50), en_max(50), lvl(1), name("Scavtrap"), melee(20), ranged(15), armor(3)
{
	std::srand(std::time(0));
	std::cout << "D00R-TP created, name defaulting to \"Scavtrap\"" << std::endl;
}

ScavTrap::ScavTrap(std::string n) :
hp(100), hp_max(100), en(50), en_max(50), lvl(1), name(n), melee(20), ranged(15), armor(3)
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

void ScavTrap::meleeAttack(const std::string target)
{
	std::cout
		<< name << " did " << melee
		<< " melee dmg to " << target << std::endl; 
}

void ScavTrap::rangedAttack(const std::string target)
{
	std::cout
		<< name << " did " << ranged 
		<< " ranged dmg to " << target << std::endl; 
}

void ScavTrap::takeDamage(unsigned dmg)
{
	unsigned actual = dmg;
	if (dmg < armor)
		dmg = 0;
	else
		dmg -= armor;
	if (dmg > hp)
		hp = 0;
	else
		hp -= dmg;
	std::cout
		<< name << " was dealt " << actual << " dmg, " << name
		<< " Took " << dmg << "dmg!, hp is now " << hp << std::endl;
}

void ScavTrap::beRepaired(unsigned rep)
{
	if (rep + hp > hp_max)
		hp = hp_max;
	std::cout
		<< "Healed " << rep << "hp, hp is now " << hp
		<< " and energy was replenished." << std::endl;
	en = en_max;
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
