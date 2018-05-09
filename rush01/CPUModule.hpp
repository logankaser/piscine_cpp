/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 17:25:40 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_H
#define CPUMODULE_H

#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule
{
public:
	CPUModule(void);
	CPUModule(std::string, module_type);
	CPUModule(const CPUModule&);
	CPUModule& operator=(const CPUModule&);
	~CPUModule(void);
	void update(void);
};

#endif
