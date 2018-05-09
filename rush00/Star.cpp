/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:30:01 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/14 22:41:42 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Star.hpp"


Star::Star(void) {}

Star::Star(int x, int y): _x(x), _y(y)
{
	char stars[3] = {'*', '.', '+'};
	_ch = stars[rand() % 3];
}

Star::~Star(void) {}

Star& Star::operator=(const Star &other)
{
	_x = other._x;
	_y = other._y;
	_ch = other._ch;
	return *this;
}

Star::Star(const Star &other)
{
	operator=(other);
}

bool Star::update(int frame, int, int, Star*[])
{
	if (frame % 10 == 0)
		_x -= 1;
	 if (_x < 0)
		return (0);
	return 1;
}

void Star::draw(void) const
{
	attron(COLOR_PAIR(2));
	mvaddch(_y, _x, _ch);
	attroff(COLOR_PAIR(2));
}

void Star::setPos(int x, int y)
{
	_x = x;
	_y = y;
}
