/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyProj.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:01:40 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 22:51:10 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYPROJ_HPP
# define ENEMYPROJ_HPP

#include "GameEntity.hpp"

class	EnemyProj : public GameEntity {
	private:
		EnemyProj(void);
	public:
		EnemyProj(int x, int y);
		~EnemyProj(void);
		EnemyProj(const EnemyProj &other);
		EnemyProj& operator=(const EnemyProj &other);
		bool collide(int x, int y);
		bool update(int, int x_max, int y_max, GameEntity* ents[]);
		void draw(void) const;
};

#endif
