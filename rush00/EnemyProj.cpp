/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyProj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:58:44 by wlin              #+#    #+#             */
/*   Updated: 2018/01/15 19:10:13 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "GameEntity.hpp"
#include "EnemyProj.hpp"

EnemyProj::EnemyProj(void) {}

EnemyProj::EnemyProj(int x, int y) : GameEntity(x , y, "EnemyProj") {}

EnemyProj::EnemyProj::~EnemyProj(void) {}

EnemyProj::EnemyProj(EnemyProj const &other) {
	*this = other;
}

EnemyProj& EnemyProj::operator = (const EnemyProj &src) {
	_type = src.getType();
	_x = src.getX();
	_y = src.getY();
	return *this;
}

bool EnemyProj::collide(int x, int y) {
	return (_x == x && _y == y);
}

bool EnemyProj::update(int f, int, int, GameEntity*[]) {
	if (f % 6 == 0)
		--_x;
	if (_colliding == "PlayerProj" || _colliding == "Player")
		return 0;
	return (_x > 0);
}

void EnemyProj::draw(void) const {
 	attron(A_BOLD);
 	attron(COLOR_PAIR(1));
	mvaddch(_y,_x, '@');
 	attroff(COLOR_PAIR(1));
 	attroff(A_BOLD);
}
