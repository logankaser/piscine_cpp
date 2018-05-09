/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 20:30:12 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_H
#define RAMMODULE_H

#include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule
{
private:
	int _pagesize;
	long _total;
public:
	RAMModule(void);
	RAMModule(std::string, module_type);
	RAMModule(const RAMModule&);
	RAMModule& operator=(const RAMModule&);
	~RAMModule(void);
	void update(void);
};

#endif
