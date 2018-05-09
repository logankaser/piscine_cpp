/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 17:18:26 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist(void) {}

PowerFist::PowerFist(const PowerFist &other)
{
    operator=(other);
}

PowerFist& PowerFist::operator=(const PowerFist &other)
{
    if (this == &other)
        return *this;
    name = other.name;
    apcost = other.apcost;
	damage = other.damage;
    return *this;
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
