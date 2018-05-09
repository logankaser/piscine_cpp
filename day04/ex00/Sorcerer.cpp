/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 14:45:51 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
}

Sorcerer::Sorcerer(std::string n, std::string t) : name(n), title(t)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

Sorcerer& Sorcerer::operator=(const Sorcerer &other)
{
    std::cout << name << " assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    name = other.name;
    title = other.title;
    return *this;
}

std::string Sorcerer::getName(void) const {return name;}
std::string Sorcerer::getTitle(void) const {return title;}

std::ostream &operator<<(std::ostream &strm, const Sorcerer &s)
{
    strm << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" << std::endl;
    return strm;
}

void Sorcerer::polymorph(const Victim &v) const
{
	v.getPolymorphed();
}
