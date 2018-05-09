/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 17:18:49 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle(void) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &other)
{
    operator=(other);
}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle &other)
{
    if (this == &other)
        return *this;
    name = other.name;
    apcost = other.apcost;
	damage = other.damage;
    return *this;
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
