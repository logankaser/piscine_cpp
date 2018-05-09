/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:30:01 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/14 21:29:28 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity(void) {}

GameEntity::GameEntity(int x, int y, std::string type) : _x(x), _y(y), _type(type)
{
	_colliding = "";
}

GameEntity::~GameEntity(void)
{
}

GameEntity& GameEntity::operator=(const GameEntity &other)
{
	_x = other._x;
	_y = other._y;
	_type = other._type;
	return *this;
}

GameEntity::GameEntity(const GameEntity &other)
{
	operator=(other);
}

std::string GameEntity::getType(void) const {return _type;}
int GameEntity::getX(void) const {return _x;}
int GameEntity::getY(void) const {return _y;}
void GameEntity::setColliding(std::string c) {_colliding = c;}


bool GameEntity::collide(int, int) {return 0;}
bool GameEntity::update(int, int, int, GameEntity*[]) {return 0;}
void GameEntity::draw() const {}
