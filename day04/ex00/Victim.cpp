/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/1w 12:05:44 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/12 14:55:50 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"

Victim::Victim(void)
{
}

Victim::Victim(std::string n) : name(n)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << name << " just died for no apprent reason !" << std::endl;
}

Victim::Victim(const Victim &other)
{
    std::cout << name << " copy constructor called" << std::endl;
    operator=(other);
}

Victim& Victim::operator=(const Victim &other)
{
    std::cout << name << " assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    name = other.name;
    title = other.title;
    return *this;
}

std::string Victim::getName(void) const {return name;}

void Victim::getPolymorphed(void) const
{
	std::cout << name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &operator<<(std::ostream &strm, const Victim &v)
{
    strm << "I'm " << v.getName() << " and I like otters !" << std::endl;
    return strm;
}
