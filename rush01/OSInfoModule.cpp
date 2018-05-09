/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 17:26:11 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

OSInfoModule::OSInfoModule(void) :
IMonitorModule("OS Info", mt_table)
{
	_strings = std::vector<std::string>(1);
	char os_release[256];
	char os_type[256];
	size_t size = sizeof os_release;
	sysctlbyname("kern.osrelease", &os_release, &size, 0, 0);
	size = sizeof os_type;
	sysctlbyname("kern.ostype", &os_type, &size, 0, 0);
	_strings[0] = std::string(os_type) + " " + std::string(os_release);
}

OSInfoModule::~OSInfoModule(void) {}
OSInfoModule& OSInfoModule::operator=(const OSInfoModule&) { return *this; }
OSInfoModule::OSInfoModule(const OSInfoModule& r) { *this = r; }
void OSInfoModule::update(void) {}
