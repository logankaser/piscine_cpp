# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2018/01/21 21:12:59 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_monitor
LIST = main IMonitorModule IMonitorDisplay\
NamesModule DateTimeModule OSInfoModule CPUModule RAMModule NetModule\
NCursesDisplay SFMLDisplay

SRC = $(addsuffix .cpp, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CPPFLAGS = $(shell pkg-config --cflags sfml-window sfml-graphics sfml-system)
LDFLAGS = $(shell pkg-config --libs sfml-window sfml-graphics sfml-system) -lncurses
CFLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SRC) -o $(NAME)
	@echo "\033[32;1m"$(NAME)" created\033[0m"

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
