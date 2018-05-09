/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 16:38:01 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(void) {}
Enemy::Enemy(int h, const std::string &t) : hp(h), type(t) {}
Enemy::~Enemy(void) {}

Enemy::Enemy(const Enemy &other)
{
    operator=(other);
}

Enemy& Enemy::operator=(const Enemy &other)
{
    if (this == &other)
        return *this;
    hp = other.hp;
	type = other.type;
    return *this;
}

std::string Enemy::getType(void) const {return type;}

void takeDamage(int)
{

}
