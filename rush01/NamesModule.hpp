/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NamesModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/20 19:55:16 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESMODULE_H
#define NAMESMODULE_H

#include "IMonitorModule.hpp"

class NamesModule : public IMonitorModule
{
public:
	NamesModule(void);
	NamesModule(std::string, module_type);
	NamesModule(const NamesModule&);
	NamesModule& operator=(const NamesModule&);
	~NamesModule(void);
	void update(void);
};

#endif
