/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:10:06 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 16:15:12 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent gate("Pizza");
	Zombie z("Sue", "Pasta");
	z.announce();
	Zombie *a;
	Zombie *b;
	Zombie *c;

	a = gate.randomChump();
	a->announce();
	b = gate.randomChump();
	b->announce();
	c = gate.randomChump();
	c->announce();
	delete a;
	delete b;
	delete c;
	return (0);
}
