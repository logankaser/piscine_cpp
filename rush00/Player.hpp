/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:39:07 by lkaser            #+#    #+#             */

/*   Updated: 2018/01/14 19:56:23 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include "GameEntity.hpp"

class Player : public GameEntity {
	private:
		Player(void);
	public:
		Player(int x, int y);
		Player(const Player &src);
		~Player(void);
		Player& operator=(const Player &rhs);
		bool collide(int x, int y);
		bool update(int frame, int x_max, int y_max, GameEntity*[]);
		void draw() const;
};

#endif
