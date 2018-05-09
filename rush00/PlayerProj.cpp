/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerProj.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:55:06 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 21:41:32 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "PlayerProj.hpp"

PlayerProj::PlayerProj(void) {}

PlayerProj::PlayerProj(int x, int y) : GameEntity(x , y, "PlayerProj") {}

PlayerProj::~PlayerProj(void) {}

PlayerProj::PlayerProj(const PlayerProj &other) {
	*this = other;
}

PlayerProj& PlayerProj::operator=(const PlayerProj &other) {
	_type = other._type;
	_x = other._x;
	_y = other._y;
	return *this;
}

bool PlayerProj::collide(int x, int y) {
	return (_x == x && _y == y);
}

bool PlayerProj::update(int, int x_max, int, GameEntity*[]) {
	++_x;
	if (_colliding == "EnemyProj" || _colliding == "Enemy")
		return 0;
	return (_x < x_max);
}

void PlayerProj::draw(void) const {
	attron(A_BOLD);
	attron(COLOR_PAIR(3));
	mvaddch(_y,_x, '~');
	attroff(COLOR_PAIR(3));
	attroff(A_BOLD);
}
