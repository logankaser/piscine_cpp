/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFMLDisplay.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:52:41 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 21:21:06 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFMLDISPLAY_H
#define SFMLDISPLAY_H

#include "IMonitorDisplay.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class SFMLDisplay : IMonitorDisplay
{
private:
	sf::Font _clear_sans;
	sf::RenderWindow* _window;
public:
	SFMLDisplay(void);
	SFMLDisplay(const SFMLDisplay&);
	SFMLDisplay& operator=(const SFMLDisplay&);
	~SFMLDisplay(void);
	int draw(std::vector<IMonitorModule*>);
};

#endif
