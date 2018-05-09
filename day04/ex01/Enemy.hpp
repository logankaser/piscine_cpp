/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 16:40:10 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ENEMY_H
# define ENEMY_H
class Enemy
{
	private:
		Enemy(void);
	protected:
		int	hp;
		std::string type;
	public:
		Enemy(int hp, const std::string&);
		Enemy(const Enemy&);
		virtual ~Enemy(void);
		Enemy& operator=(const Enemy&);
		std::string getType(void) const;
		int getHP(void) const;
		virtual void takeDamage(int);
};

#endif
