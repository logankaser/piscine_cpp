/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NamesModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 18:28:43 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NamesModule.hpp"
#include <unistd.h>

NamesModule::NamesModule(void) :
IMonitorModule("Username / Hostname", mt_table)
{
	_strings = std::vector<std::string>(2);
	_strings[0] = "...";
	_strings[1] = "...";
}
NamesModule::~NamesModule(void) {}
NamesModule& NamesModule::operator=(const NamesModule&) { return *this; }
NamesModule::NamesModule(const NamesModule& r) { *this = r; }

void NamesModule::update(void)
{
	char user[256];
	char host[256];
	getlogin_r(user, 256);
	gethostname(host, 256);
	_strings[0] = std::string(user);
	_strings[1] = std::string(host);
}
