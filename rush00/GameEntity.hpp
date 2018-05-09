/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:39:07 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/14 21:29:40 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

#include <iostream>

class GameEntity {
	protected:
		GameEntity(void);
		int _x;
		int _y;
		std::string _type;
		std::string _colliding;
	public:
		GameEntity(int x, int y, std::string type);
		GameEntity(const GameEntity&);
		virtual ~GameEntity(void);
		GameEntity& operator=(const GameEntity&);
		std::string getType(void) const;
		int getX(void) const;
		int getY(void) const;
		void setColliding(std::string);
		virtual bool collide(int x, int y);
		virtual bool update(int frame, int x_max, int y_max, GameEntity* ents[]);
		virtual void draw(void) const;
};

#endif
