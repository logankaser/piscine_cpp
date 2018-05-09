/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 20:46:39 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETMODULE_H
#define NETMODULE_H

#include "IMonitorModule.hpp"

class NetModule : public IMonitorModule
{
public:
	NetModule(void);
	NetModule(std::string, module_type);
	NetModule(const NetModule&);
	NetModule& operator=(const NetModule&);
	~NetModule(void);
	void update(void);
};

#endif
