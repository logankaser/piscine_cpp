/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHoard.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:43:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 16:10:35 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHoard.hpp"

ZombieHoard::ZombieHoard(unsigned n) : count(n)
{
	std::srand(std::time(0));
	static std::string pool[] = {
		"Brad", "Tim", 
		"Susan", "Kim",
		"Brittney", "Sam"
	};
	hoard = new Zombie*[count];
	unsigned i = 0;
	while (i < count)
		hoard[i++] = new Zombie(pool[std::rand() % 6], "Hoard");
}

ZombieHoard::~ZombieHoard(void)
{
	while (count)
		delete hoard[--count];
	delete hoard;
	std::cout << "A Hoard of Zombies is no more." << std::endl;
}

void	ZombieHoard::announce()
{
	unsigned i = 0;
	while (i < count)
		hoard[i++]->announce();
}
