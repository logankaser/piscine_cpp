# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by lkaser            #+#    #+#              #
#    Updated: 2018/01/09 18:55:14 by lkaser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
LIST = replace

SRC = $(addsuffix .cpp, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CCFLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJ)
	@g++ $(SRC) $(CCFLAGS) -o $(NAME)
	@echo "\033[32;1mExecutable created\033[0m"

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
