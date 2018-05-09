/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:53:51 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#ifndef NINJATRAP_H
# define NINJATRAP_H
class NinjaTrap : public virtual ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(const std::string);
		NinjaTrap(const NinjaTrap&);
		~NinjaTrap(void);
		NinjaTrap& operator=(const NinjaTrap&);
		void ninjaShoebox(const ClapTrap&);
		void ninjaShoebox(const FragTrap&);
		void ninjaShoebox(const ScavTrap&);
		void ninjaShoebox(const NinjaTrap&);
};
#endif
