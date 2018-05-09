/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:45:27 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 22:16:56 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"

class	Enemy : public GameEntity {
	private:
		Enemy(void);
	public:
		Enemy(double x, double y);
		~Enemy(void);
		Enemy(const Enemy &other);
		Enemy &operator = (const Enemy &other);

		bool collide(int x, int y);
		bool update(int frame, int x_max, int y_max, GameEntity* ent[]);
		void draw() const;
};

void spawn_enemy(int x_max, int y_max, GameEntity *ent[]);

#endif
