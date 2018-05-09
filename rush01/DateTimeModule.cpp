/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:58 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 17:31:46 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTimeModule.hpp"
#include <ctime>

DateTimeModule::DateTimeModule(void) :
IMonitorModule("Time", mt_table)
{
	_strings = std::vector<std::string>(2);
	_strings[0] = "...";
	_strings[1] = "...";
}
DateTimeModule::~DateTimeModule(void) {}
DateTimeModule& DateTimeModule::operator=(const DateTimeModule&) { return *this; }
DateTimeModule::DateTimeModule(const DateTimeModule& r) { *this = r; }

std::string getOrdCon(unsigned n)
{
	std::string ns = std::to_string(n);
	if (n > 3 && n < 21)
		return ns + "th";
	switch (n % 10) {
		case  1: return ns + "st";
		case  2: return ns + "nd";
		case  3: return ns + "rd";
		default: return ns + "th";
	}
}

void DateTimeModule::update(void)
{
	static std::string days[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Whensday",
		"Thursday",
		"Friday",
		"Saturday",
	};
	static std::string months[] = {
		"January", "February"
		"March", "April",
		"May", "June",
		"July", "August"
		"September", "October"
		"November", "December"
	};
	std::time_t t = std::time(0);
	std::tm* lt = localtime(&t);
	_strings[0] =
		days[lt->tm_wday] + ", the " + getOrdCon(lt->tm_mday) +
		" of " + months[lt->tm_mon];
	_strings[1] =
		std::to_string(lt->tm_hour) + ':' +
		(lt->tm_min < 10 ? '0' + std::to_string(lt->tm_min) : std::to_string(lt->tm_min)) + ':' +
		(lt->tm_sec < 10 ? '0' + std::to_string(lt->tm_sec) : std::to_string(lt->tm_sec));
}
