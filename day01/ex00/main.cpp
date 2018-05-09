/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:20:01 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 18:02:07 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int	main(void)
{
	Pony normal("Tim", "brown", "light brown", FRIENDLY);
	Pony wild("Justin", "black", "white", WILD);
	Pony wierd("#$%&^$$", "all", "everything", ERROR);
	Pony loud("Brad", "pink", "green", LOUD);
	normal.print_desc();
	normal.pat();
	normal.neigh();
	std::cout << std::endl;
	wild.print_desc();
	wild.pat();
	wild.neigh();
	std::cout << std::endl;
	wierd.print_desc();
	wierd.pat();
	wierd.neigh();
	std::cout << std::endl;
	loud.print_desc();
	loud.pat();
	loud.neigh();
	return (0);
}
