/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 16:55:58 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"

#ifndef POWERFIST_H
# define POWERFIST_H

class PowerFist : public AWeapon
{
	public:
		PowerFist(void);
		PowerFist(const PowerFist&);
		~PowerFist(void);
		PowerFist& operator=(const PowerFist&);
		void attack(void) const;
};

#endif
