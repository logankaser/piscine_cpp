/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:13:13 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 12:41:19 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H
# include <iostream>
# include <string>

typedef enum	temperament
{
	ERROR,
	FRIENDLY,
	TIMID,
	WILD,
	LOUD
}	t_temper;


class Pony
{
	std::string name;
	std::string color;
	std::string mane_color;
	t_temper temperament;
	public:
		Pony(std::string, std::string, std::string, t_temper);
		Pony(std::string, std::string, std::string);
		void print_desc();
		void pat();
		void neigh();

};

#endif
