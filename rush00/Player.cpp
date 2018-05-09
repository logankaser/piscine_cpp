/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:30:01 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/14 22:09:25 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "GameEntity.hpp"
#include "PlayerProj.hpp"
#include "Player.hpp"
#include "game.h"

Player::Player(void) : GameEntity(0, 0, "Player") {}

Player::Player(int x, int y) : GameEntity(x, y, "Player") {}

Player::~Player(void) {}

Player& Player::operator=(const Player &other)
{
	_x = other._x;
	_y = other._y;
	_type = other._type;
	return *this;
}

Player::Player(const Player &other)
{
	operator=(other);
}

bool Player::collide(int x, int y)
{
	(void)x;
	(void)y;
	return 0;
};

bool Player::update(int, int x_max, int y_max, GameEntity* ents[])
{
	int ch = getch();
	if (ch == KEY_UP)
		_y -= 1;
	if (ch == KEY_DOWN)
		_y += 1;
	if (ch == KEY_RIGHT)
		_x += 1;
	if (ch == KEY_LEFT)
		_x -= 1;
	if (ch == ' ')
	{
		for (int i = 0; i < ENT_MAX; ++i)
		{
			if (!ents[i])
			{
				ents[i] = new PlayerProj(_x + 1, _y);
				break;
			}	
		}
	}
	if (_y > y_max)
		_y = 0;
	else if (_y < 0)
		_y = y_max;
	if (_x > x_max - 2)
		_x = x_max - 2;
	if (_x < 1)
		_x = 1;
	if (_colliding == "EnemyProj")
	{
		for (unsigned i = 0; i < ENT_MAX; ++i)
		{
			delete ents[i];
		}
		endwin();
		exit(0);
	}
	return 1;
}

void Player::draw(void) const
{
	mvaddch(_y, _x, '=');
	mvaddch(_y, _x + 1, '>');
	attron(COLOR_PAIR(1));
	mvaddch(_y, _x - 1, '~');
	attroff(COLOR_PAIR(1));
}
