/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 18:42:14 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

CPUModule::CPUModule(void) :
IMonitorModule("CPU", mt_table)
{
	_strings = std::vector<std::string>(3);
	_data = std::vector<double>(3);

 	char cpu_model[256];
    size_t size = sizeof cpu_model;
    sysctlbyname("machdep.cpu.brand_string", &cpu_model, &size, 0, 0);
	_strings[0] = std::string(cpu_model);

	int hw_physicalcpu;
    int hw_logicalcpu;
    size = sizeof hw_physicalcpu;
    sysctlbyname("hw.physicalcpu", &hw_physicalcpu, &size, 0, 0);
    size = sizeof hw_logicalcpu;
    sysctlbyname("hw.logicalcpu", &hw_logicalcpu, &size, 0, 0);
    _strings[1] = std::to_string(hw_physicalcpu) + " Cores, " +
		std::to_string(hw_logicalcpu) + " Threads";
	_strings[2] = "Load average over 1/5/15 min:";
}

CPUModule::~CPUModule(void) {}
CPUModule& CPUModule::operator=(const CPUModule&) { return *this; }
CPUModule::CPUModule(const CPUModule& r) { *this = r; }
void CPUModule::update(void)
{
	double load[3];
	getloadavg(load, 3);
	_data[0] = load[0];
	_data[1] = load[1];
	_data[2] = load[2];
}
