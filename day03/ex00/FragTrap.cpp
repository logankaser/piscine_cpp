/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:38:00 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
hp(100), hp_max(100), en(100), en_max(100), lvl(1), name("Claptrap"), melee(30), ranged(20), armor(5)
{
	std::srand(std::time(0));
	std::cout << "FRAG-TP created, name defaulting to \"Claptrap\"" << std::endl;
}

FragTrap::FragTrap(std::string n) :
hp(100), hp_max(100), en(100), en_max(100), lvl(1), name(n), melee(30), ranged(20), armor(5)
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

void FragTrap::meleeAttack(const std::string target)
{
	std::cout
		<< name << " did " << melee
		<< " melee dmg to " << target << std::endl; 
}

void FragTrap::rangedAttack(const std::string target)
{
	std::cout
		<< name << " did " << ranged 
		<< " ranged dmg to " << target << std::endl; 
}

void FragTrap::takeDamage(unsigned dmg)
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

void FragTrap::beRepaired(unsigned rep)
{
	if (rep + hp > hp_max)
		hp = hp_max;
	std::cout
		<< "Healed " << rep << "hp, hp is now " << hp
		<< " and energy was replenished." << std::endl;
	en = en_max;
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
