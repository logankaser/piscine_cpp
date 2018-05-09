/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:39:07 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/14 22:09:17 by ihodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP
#include <iostream>

class Star {
	private:
		Star(void);
		int _x;
		int _y;
		char _ch;
	public:
		Star(int x, int y);
		Star(const Star &src);
		~Star(void);
		Star& operator=(const Star &rhs);
		bool update(int frame, int y_max, int, Star*[] );
		void setPos(int x, int y);
		void draw( void ) const;
};

#endif
