/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:54:24 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#ifndef SUPERTRAP_H
# define SUPERTRAP_H
class SuperTrap : public virtual FragTrap, public virtual NinjaTrap
{
	public:
		SuperTrap(void);
		SuperTrap(const std::string);
		SuperTrap(const SuperTrap&);
		~SuperTrap(void);
		SuperTrap& operator=(const SuperTrap&);
};
#endif
