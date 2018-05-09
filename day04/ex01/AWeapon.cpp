/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 17:15:43 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(void) {}
AWeapon::AWeapon(const std::string &n, int ap, int d) : name(n), apcost(ap), damage(d) {}
AWeapon::~AWeapon(void) {}

AWeapon::AWeapon(const AWeapon &other)
{
    operator=(other);
}

AWeapon& AWeapon::operator=(const AWeapon &other)
{
    if (this == &other)
        return *this;
    name = other.name;
    apcost = other.apcost;
	damage = other.damage;
    return *this;
}

std::string AWeapon::getName(void) const {return name;}
int AWeapon::getAPCost(void) const {return apcost;}
int AWeapon::getDamage(void) const {return damage;}

void AWeapon::attack(void) const {}
