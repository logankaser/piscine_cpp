/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:27:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 17:18:11 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef AWEAPON_H
# define AWEAPON_H
class AWeapon
{
	protected:
		std::string name;
		int	apcost;
		int damage;
	public:
		AWeapon(void);
		AWeapon(const std::string&, int, int);
		AWeapon(const AWeapon&);
		~AWeapon(void);
		AWeapon& operator=(const AWeapon&);
		std::string getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;
		virtual void attack(void) const;
};

#endif
