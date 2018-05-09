/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:43:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/11 15:54:41 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(std::string t) : type(t)
{
	std::srand(std::time(0));
	std::cout << "A gateway of " << type << " Zombies appeared." << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
	std::srand(std::time(0));
	std::cout << "A gateway of " << type << " Zombies closed." << std::endl;
}

void ZombieEvent::setZombieType(std::string t)
{
	type = t;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return new Zombie(name, type);
}

Zombie* ZombieEvent::randomChump(void)
{
	static std::string pool[] = {
		"Brad", "Tim", 
		"Susan", "Kim",
		"Brittney", "Sam"
	};
	return new Zombie(pool[std::rand() % 6], type);
}
