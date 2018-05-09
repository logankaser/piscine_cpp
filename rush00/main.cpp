/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:20:32 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 16:52:56 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <unistd.h>
#include "game.h"
#include "GameEntity.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "PlayerProj.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"

void	init_ncurses( void )
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	timeout(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	return;
}

void	make_scene(Star *stars[], int x_max, int y_max)
{
	y_max -= 6;
	for (unsigned i = 0; i < STAR_MAX; ++i)
		stars[i] = new Star(rand() % x_max, rand() % y_max - 6);
}

void	update_scene(Star *stars[], int x_max, int y_max, int frame)
{
	y_max -= 6;
	for (unsigned i = 0; i < STAR_MAX; ++i)
	{
		if (stars[i])
		{
			if (stars[i]->update(frame, x_max, y_max, stars))
				stars[i]->draw();
			else
				stars[i]->setPos(rand() % x_max, rand() % y_max - 6);
		}
	}
}

void	display_time( time_t start_time, int x_max, int y_max)
{
	time_t curr_time = time(0);

	(void)x_max;
	if (start_time - curr_time != 0)
	{
		mvprintw(y_max - 3, 10, "Time: %i ", curr_time - start_time);
		refresh();
	}
}

void	draw_score_box(int x_max, int y_max)
{
	mvaddch(y_max - 5, 1, ACS_ULCORNER);
	mvaddch(y_max - 5, x_max - 1, ACS_URCORNER);
	mvaddch(y_max - 1, 1, ACS_LLCORNER);
	mvaddch(y_max - 1, x_max - 1, ACS_LRCORNER);

	for(int i = 2; i < x_max - 1; i++)
		mvaddch(y_max - 5, i, ACS_HLINE);

	for(int i = y_max - 5 + 1; i < y_max - 1; i++)
		mvaddch(i, 1, ACS_VLINE);

	for(int i = y_max - 5 + 1; i < y_max - 1; i++)
		mvaddch(i, x_max - 1, ACS_VLINE);

	for(int i = 2; i < x_max - 1; i++)
		mvaddch(y_max - 1, i, ACS_HLINE);
	return;
}

void	del_star(Star *stars[])
{
	for(unsigned i = 0; i < STAR_MAX; i++)
		delete stars[i];
	delete [] stars;
}

int	main(void)
{
	int x_max = 0;
	int y_max = 0;
	int frame = 0;
	GameEntity* ents[ENT_MAX] = {0};
	Star*		stars[STAR_MAX] = {0};
	time_t		start_time = time(0);

	ents[0] = new Player(1, 1);
	init_ncurses();
	getmaxyx(stdscr, y_max, x_max);
	make_scene(stars, x_max, y_max);
	while (1)
	{
		clear();
		update_scene(stars, x_max, y_max, frame);
		spawn_enemy(x_max, y_max, ents);
		spawn_boss(x_max, y_max, ents);
		for (unsigned i = 0; i < ENT_MAX; ++i)
		{
			if (!ents[i])
				continue;
			for (unsigned j = i + 1; j < ENT_MAX; ++j)
			{
				if (ents[j] && ents[i] && ents[j]->collide(ents[i]->getX(), ents[i]->getY()))
				{
					ents[j]->setColliding(ents[i]->getType());
					ents[i]->setColliding(ents[j]->getType());
				}
			}
		}
		for (unsigned i = 0; i < ENT_MAX; ++i)
		{
			if (ents[i])
			{
				if (ents[i]->update(frame, x_max, y_max, ents))
					ents[i]->draw();
				else
				{
					delete ents[i];
					ents[i] = 0;
				}
			}
		}
		display_time( start_time, x_max, y_max);
		draw_score_box(x_max, y_max);
		refresh();
		if (++frame > 255)
			frame = 0;
		usleep(2000);
	}
	del_star(stars);
	endwin();
}
