# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2018/01/14 21:57:46 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
LIST = GameEntity Player EnemyProj PlayerProj Enemy main Star Boss

SRC = $(addsuffix .cpp, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CCFLAGS = -O3 -Wall -Wextra -Werror -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(SRC) $(CCFLAGS) -o $(NAME)
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
