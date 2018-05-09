/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 20:41:55 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>

RAMModule::RAMModule(void) :
IMonitorModule("RAM", mt_table)
{
	_strings = std::vector<std::string>(2);
	_data = std::vector<double>(2);

    size_t size = sizeof _total;
    sysctlbyname("hw.memsize", &_total, &size, 0, 0);
	_strings[0] = "Total Memory: " + std::to_string(_total / 1048576) + "mb";
	size = sizeof _pagesize;
    sysctlbyname("hw.pagesize", &_pagesize, &size, 0, 0);
	_strings[1] = "Memory Used/Free";
}

RAMModule::~RAMModule(void) {}
RAMModule& RAMModule::operator=(const RAMModule&) { return *this; }
RAMModule::RAMModule(const RAMModule& r) { *this = r; }
void RAMModule::update(void)
{
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	host_statistics64(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count);
	double used = (vmstat.active_count + vmstat.inactive_count + vmstat.wire_count) * _pagesize;
	double free = _total - used;
	_data[0] = used / 1024 / 1024;
	_data[1] = free / 1024 / 1024;
}
