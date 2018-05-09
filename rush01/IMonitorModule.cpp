/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 17:51:36 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule(void) {}

IMonitorModule::IMonitorModule(std::string name, module_type type) : _name(name), _type(type) {}

IMonitorModule& IMonitorModule::operator=(const IMonitorModule& r) {
	_name = r._name;
	_type = r._type;
	_data = r._data;
	_strings = r._strings;
	return *this;
}

IMonitorModule::~IMonitorModule(void) {}

IMonitorModule::IMonitorModule(const IMonitorModule& r) 
{
	operator=(r);
}

std::vector<std::string> IMonitorModule::getStrings(void) { return _strings; }
std::vector<double> IMonitorModule::getData(void) { return _data; }
std::string IMonitorModule::getName(void) { return _name; }
