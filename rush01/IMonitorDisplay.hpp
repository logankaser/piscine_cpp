/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:52:41 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 21:21:38 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_H
#define IMONITORDISPLAY_H

#include "IMonitorModule.hpp"
#include <string>
#include <vector>

class IMonitorDisplay
{
protected:
	IMonitorDisplay(void);
public:
	IMonitorDisplay(const IMonitorDisplay&);
	IMonitorDisplay& operator=(const IMonitorDisplay&);
	~IMonitorDisplay(void);
	virtual int draw(std::vector<IMonitorModule*>) = 0;
};

#endif
