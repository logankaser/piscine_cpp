/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/20 19:55:04 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_H
#define DATETIMEMODULE_H

#include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule
{
public:
	DateTimeModule(void);
	DateTimeModule(std::string, module_type);
	DateTimeModule(const DateTimeModule&);
	DateTimeModule& operator=(const DateTimeModule&);
	~DateTimeModule(void);
	void update(void);
};

#endif
