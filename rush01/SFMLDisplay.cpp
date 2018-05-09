/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFMLDisplay.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 21:24:21 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 21:54:15 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"
#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay(void)
{
	_window = new sf::RenderWindow(sf::VideoMode(400, 1000), "ft_monitor");
	_clear_sans.loadFromFile("./clear_sans.ttf");
}

SFMLDisplay& SFMLDisplay::operator=(const SFMLDisplay&) { return *this; }
SFMLDisplay::~SFMLDisplay(void)
{
	delete _window;
}
SFMLDisplay::SFMLDisplay(const SFMLDisplay& r) { *this = r; }

int	SFMLDisplay::draw(std::vector<IMonitorModule*> modules)
{
	sf::Event event;
	while (_window->pollEvent(event))
		if (event.type == sf::Event::Closed)
		{
			_window->close();
			return 0;
		}
	sf::Text txt;
	txt.setFont(_clear_sans);
	txt.setCharacterSize(20);
	
	_window->clear();
	unsigned line = 0;
	std::vector<IMonitorModule*>::iterator mod;
	for (mod = modules.begin(); mod != modules.end(); ++mod) {
		(*mod)->update();
		std::vector<std::string> _strs = (*mod)->getStrings();
		std::vector<std::string>::iterator strs;	
		txt.setCharacterSize(36);
		txt.setString((*mod)->getName() + ' ');
		txt.setPosition(0, (line += 20));
		_window->draw(txt);
		line += 36;

		txt.setCharacterSize(20);
		for (strs = _strs.begin(); strs != _strs.end(); ++strs) {
			txt.setString(*strs);
			txt.setPosition(0, (line += 20));
			_window->draw(txt);
		}
		std::vector<double> _data = (*mod)->getData();
		std::vector<double>::iterator data;
		for (data = _data.begin(); data != _data.end(); ++data) {
			txt.setString(std::to_string(*data));
			txt.setPosition(0, (line += 20));
			_window->draw(txt);	
		}
		line += 20;
	}
	_window->display();
	return 1;
}
