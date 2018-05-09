/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:28:13 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/09 12:56:26 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string n, std::string c, std::string mc, t_temper t) {
	name = n;
	color = c;
	mane_color = mc;
	temperament = t;
}

Pony::Pony(std::string n, std::string c, std::string mc) {
	name = n;
	color = c;
	mane_color = mc;
	temperament = ERROR;
}

void Pony::print_desc()
{
	std::cout
		<< "The Pony's name is " << name << ',' << std::endl
		<< "it's coat is " << color << ',' << std::endl
		<< "and it's mane is " << mane_color << std::endl
		<< "It has a ";
	switch (temperament) {
		case 0:
			std::cout << "non-euclidean temperament???" << std::endl;
			break;
		case 1:
			std::cout << "friendly temperament." << std::endl;
			break;
		case 2:
			std::cout << "timid temperament." << std::endl;
			break;
		case 3:
			std::cout << "wild temperament." << std::endl;
			break;
		case 4:
			std::cout
				<< "loud and annoying temper--" << std::endl
				<< "HELLO IT IS LOUND PONY" << std::endl
				<< "IT IS TIME FOR THE LOUD NEEEEEIIIIIIIIGGHHHHHH!!!" << std::endl
				<< "BUSH DID 9/11!!!" << std::endl
				<< "VACCINES CAUSE AUTISM!!!" << std::endl
				<< "MAKE AMERICA GREAT A--" << std::endl
				<< "(Did that pony just talk?)" << std::endl;
			break;
	}
}
void Pony::pat()
{
	std::cout << "You pat the pony, it.." << std::endl;
	switch (temperament) {
		case 0:
			std::cout
				<< "Becomes a turtle.." << std::endl
				<< "(what?)" << std::endl;
			break;
		case 1:
			std::cout << "Neighs in a friendly manner." << std::endl;
			break;
		case 2:
			std::cout << "Edges away from you." << std::endl;
			break;
		case 3:
			std::cout << "Is not there because it is out partying." << std::endl;
			break;
		case 4:
			std::cout
				<< "Sues you for sexual harassment." << std::endl
				<< "The case goes well for you and you don't have to pay lawyer fees," << std::endl
				<< "but your \"friends\" now send you pony body pillows." << std::endl;
			break;
	}
}
void Pony::neigh()
{
	std::cout << "The pony neighs.." << std::endl;
	switch (temperament) {
		case 0:
			std::cout
				<< "It sings the song of creation.." << std::endl
				<< "(hmmm...)" << std::endl;
			break;
		case 1:
			std::cout << "It neighs in a friendly manner." << std::endl;
			break;
		case 2:
			std::cout << "It makes a very small noise." << std::endl;
			break;
		case 3:
			std::cout << "It neighs a guitar solo." << std::endl;
			break;
		case 4:
			std::cout << "The loud pony is already nieghing, actually it never stops..." << std::endl;
			break;
	}
}
