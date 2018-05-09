/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:28 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 21:22:37 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"
#include "NCursesDisplay.hpp"
#include <ncurses.h>
#include <algorithm>

NCursesDisplay::NCursesDisplay(void)
{
	initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
}
NCursesDisplay& NCursesDisplay::operator=(const NCursesDisplay&) { return *this; }
NCursesDisplay::~NCursesDisplay(void)
{
	clear();
	endwin();
}
NCursesDisplay::NCursesDisplay(const NCursesDisplay& r) { *this = r; }

int NCursesDisplay::draw(std::vector<IMonitorModule*> modules)
{
	clear();
	unsigned line = 0;
	std::vector<IMonitorModule*>::iterator mod;
	for (mod = modules.begin(); mod != modules.end(); ++mod)
	{
		(*mod)->update();
		std::vector<std::string> _strs = (*mod)->getStrings();
		std::vector<std::string>::iterator strs;
		attron(A_BOLD);
    	attron(COLOR_PAIR(4));
		mvprintw(line, 0, "==============================");
		mvprintw(line++, 0, ((*mod)->getName() + ' ').c_str());
    	attroff(COLOR_PAIR(4));
    	attroff(A_BOLD);
		for (strs = _strs.begin(); strs != _strs.end(); ++strs)
			mvprintw(line++, 0, (*strs).c_str());
		
		std::vector<double> _data = (*mod)->getData();
		std::vector<double>::iterator data;
		for (data = _data.begin(); data != _data.end(); ++data)
			mvprintw(line++, 0, std::to_string(*data).c_str());
		mvprintw(line++, 0, "------------------------------");
		++line;
	}
	refresh();
	return 1;
}
