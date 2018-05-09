/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 14:50:13 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Peon.hpp"

Peon::Peon(void)
{
}

Peon::Peon(std::string n) : Victim(n)
{
	std::cout << "Zog zop." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

Peon& Peon::operator=(const Peon &other)
{
    std::cout << name << " assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    name = other.name;
    title = other.title;
    return *this;
}

void Peon::getPolymorphed(void) const
{
    std::cout << name << " has been turned into a pink pony !" << std::endl;
}
