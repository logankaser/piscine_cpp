/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:57:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 13:53:37 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string);
		FragTrap(const FragTrap&);
		~FragTrap(void);
		FragTrap& operator=(const FragTrap&);
		void vaulthunter_dot_exe(const std::string);
};
#endif
