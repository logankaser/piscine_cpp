/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 16:18:39 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay(void) {}
IMonitorDisplay& IMonitorDisplay::operator=(const IMonitorDisplay&) { return *this; }
IMonitorDisplay::~IMonitorDisplay(void) {}
IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay& r) { *this = r; }
