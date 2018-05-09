/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:32:04 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 22:46:45 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "Boss.hpp"
#include "EnemyProj.hpp"
#include "game.h"

Boss::Boss(void) {}

Boss::Boss(double x, double y) : GameEntity(x, y, "Boss")
{
	_hp = 20;
	_timer = 0;
}

Boss::~Boss(void) {}

Boss::Boss(const Boss &other) {
	*this = other;
}

Boss &Boss::operator = (const Boss &other) {
	_type = other._type;
	_x = other._x;
	_y = other._y;
	return (*this);
}

bool Boss::collide(int x, int y) {
	return (_x == x && _y == y);
}

bool Boss::update(int, int, int, GameEntity* ents[]) {
	if (_colliding == "PlayerProj")
	{
		--_hp;
		_colliding = "";
	}
	if (_hp < 0)
		return 0;
	if (_timer == 500)
	{
		--_x;
		if (_x == 0)
			return (0);
	}
	if (_timer > 995)
	{
		for (unsigned i = 0; i < ENT_MAX; ++i)
		{
			if (!ents[i])
			{
				ents[i] = new EnemyProj(_x - 2, _y);
				break;
			}
		}
	}
	if (_timer > 1000)
		_timer = 0;
	++_timer;
	return (1);
}

void Boss::draw() const {
	attron(COLOR_PAIR(4));
	mvaddch(_y,_x, '}');
	mvaddch(_y,_x + 1, '~');
	mvaddch(_y,_x + 2, '~');
	attroff(COLOR_PAIR(4));
}

void spawn_boss(int x_max, int y_max, GameEntity *ents[])
{
	static unsigned timer = 0;
	if (timer == 2048)
	{

		for (int i = 0; i < ENT_MAX; i++)
		{
			if (!ents[i])
			{
				ents[i] = new Boss(x_max - 1, std::rand() % (y_max - 6));
				break;
			}
		}
		timer = 0;
	}
	++timer;
}
