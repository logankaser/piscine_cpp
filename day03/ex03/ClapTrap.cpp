/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:44:51 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
hp(100), hp_max(100), en(100), en_max(100), lvl(1), name("Claptrap"), melee(30), ranged(20), armor(5)
{
	std::srand(std::time(0));
	std::cout << "Claptrap created, name defaulting to \"Claptrap\"" << std::endl;
}

ClapTrap::ClapTrap(unsigned h, unsigned hm, unsigned e, unsigned em, unsigned lv,
std::string n, unsigned m, unsigned r, unsigned a) :
hp(h), hp_max(hm), en(e), en_max(em), lvl(lv), name(n), melee(m), ranged(r), armor(a)
{
	std::srand(std::time(0));
	std::cout << "Claptrap created, named " << name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Claptrap " << name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
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

void ClapTrap::meleeAttack(const std::string target)
{
	std::cout
		<< name << " did " << melee
		<< " melee dmg to " << target << std::endl; 
}

void ClapTrap::rangedAttack(const std::string target)
{
	std::cout
		<< name << " did " << ranged 
		<< " ranged dmg to " << target << std::endl; 
}

void ClapTrap::takeDamage(unsigned dmg)
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

void ClapTrap::beRepaired(unsigned rep)
{
	if (rep + hp > hp_max)
		hp = hp_max;
	std::cout
		<< "Healed " << rep << "hp, hp is now " << hp
		<< " and energy was replenished." << std::endl;
	en = en_max;
}
