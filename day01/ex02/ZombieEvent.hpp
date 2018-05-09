/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:10:59 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 15:14:35 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H
# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
    std::string type;
    public:
        ZombieEvent(std::string);
		~ZombieEvent(void);
		void setZombieType(std::string);
        Zombie* newZombie(std::string);
		Zombie* randomChump(void);
};

#endif
