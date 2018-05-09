/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:26:31 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 22:35:40 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP
# define BOSS_HPP

# include "GameEntity.hpp"

class	Boss : public GameEntity {
	private:
		Boss(void);
		int _hp;
		int _timer;

	public:
		Boss(double x, double y);
		~Boss(void);
		Boss(Boss const &src);
		Boss &operator = (Boss const &src);

		bool collide(int x, int y);
		bool update(int frame, int x_max, int y_max, GameEntity *ents[]);
		void draw() const;
};

void spawn_boss(int x_max, int y_max, GameEntity *ent[]);

#endif
