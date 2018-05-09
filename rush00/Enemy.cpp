/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:45:26 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 22:47:02 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "Enemy.hpp"
#include "EnemyProj.hpp"
#include "game.h"

Enemy::Enemy(void) {}

Enemy::Enemy(double x, double y) : GameEntity(x, y, "Enemy") {}

Enemy::~Enemy(void) {}

Enemy::Enemy(const Enemy &other) {
	*this = other;
}

Enemy &Enemy::operator = (const Enemy &other) {
	_type = other._type;
	_x = other._x;
	_y = other._y;
	return (*this);
}

bool Enemy::collide(int x, int y) {
	return (_x == x && _y == y);
}

bool Enemy::update(int frame, int, int, GameEntity* ents[]) {
	if (_colliding == "PlayerProj")
		return 0;
	if (frame % 255 == 0)
	{
		--_x;
		for (unsigned i = 0; i < ENT_MAX; ++i)
		{
			if (!ents[i])
			{
				ents[i] = new EnemyProj(_x - 2, _y);
				break;
			}
		}
	}
	if (_x == 0)
		return (0);
	return (1);
}

void Enemy::draw() const {
	mvaddch(_y,_x, 'X');
	mvaddch(_y,_x + 1, '~');
}

void spawn_enemy(int x_max, int y_max, GameEntity *ents[])
{
	static unsigned timer = 0;
	if (timer == 1024)
	{

		for (int i = 0; i < ENT_MAX; i++)
		{
			if (!ents[i])
			{
				ents[i] = new Enemy(x_max - 1, std::rand() % (y_max - 6));
				break;
			}
		}
		timer = 0;
	}
	++timer;
}
