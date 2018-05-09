/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerProj.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:53:24 by wlin              #+#    #+#             */
/*   Updated: 2018/01/14 22:52:25 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERPROJ_HPP
# define PLAYERPROJ_HPP

# include "GameEntity.hpp"

class	PlayerProj : public GameEntity {
	protected:
		PlayerProj(void);
	public:
		PlayerProj(int x, int y);
		~PlayerProj(void);
		PlayerProj(const PlayerProj &other);
		PlayerProj& operator=(const PlayerProj &other);
		bool collide(int x, int y);
		bool update(int, int x_max, int y_max, GameEntity* ents[]);
		void draw(void) const;
};

#endif
