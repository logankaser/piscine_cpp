/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 17:25:17 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_H
#define OSINFOMODULE_H

#include "IMonitorModule.hpp"

class OSInfoModule : public IMonitorModule
{
public:
	OSInfoModule(void);
	OSInfoModule(std::string, module_type);
	OSInfoModule(const OSInfoModule&);
	OSInfoModule& operator=(const OSInfoModule&);
	~OSInfoModule(void);
	void update(void);
};

#endif
