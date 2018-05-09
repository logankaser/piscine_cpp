/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHoard.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:10:59 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 16:08:20 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HOARD_H
# define ZOMBIE_HOARD_H
# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieHoard
{
	unsigned count;
	Zombie** hoard;
    public:
        ZombieHoard(unsigned n);
		~ZombieHoard(void);
		 void	announce(void);
};

#endif
