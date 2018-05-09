/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:17:17 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 22:18:58 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NamesModule.hpp"
#include "DateTimeModule.hpp"
#include "OSInfoModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetModule.hpp"
#include "NCursesDisplay.hpp"
#include "SFMLDisplay.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <algorithm>

int	main(void)
{
	NamesModule nm;
	DateTimeModule dt;
	OSInfoModule os;
	CPUModule cpu;
	RAMModule ram;
	NetModule net;
	std::vector<IMonitorModule*> modules;
	std::ifstream config;
	config.open("ft_monitor.config");
	std::string line;
	bool graphics = false;
	while (std::getline(config, line))
	{
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		if (line == "identity")
			modules.push_back(&nm);
		else if (line == "time")
			modules.push_back(&dt);
		else if (line == "os")
			modules.push_back(&os);
		else if (line == "cpu")
			modules.push_back(&cpu);
		else if (line == "ram")
			modules.push_back(&ram);
		else if (line == "network")
			modules.push_back(&net);
		else if (line == "graphics")
			graphics = true;
	}
	if (graphics)
	{
		SFMLDisplay sfml;
		while (sfml.draw(modules))
			usleep(100000);
	}
	else
	{
		NCursesDisplay dis;
		while (dis.draw(modules))
			usleep(100000);
	}
	return 0;
}
