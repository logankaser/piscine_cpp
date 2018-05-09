/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCursesDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:52:41 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 21:21:48 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCURSESDISPLAY_H
#define INCURSESDISPLAY_H

#include "IMonitorDisplay.hpp"
#include <string>
#include <vector>

class NCursesDisplay : IMonitorDisplay
{
public:
	NCursesDisplay(void);
	NCursesDisplay(const NCursesDisplay&);
	NCursesDisplay& operator=(const NCursesDisplay&);
	~NCursesDisplay(void);
	int draw(std::vector<IMonitorModule*>);
};

#endif
