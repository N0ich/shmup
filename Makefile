#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 11:21:24 by vrey              #+#    #+#              #
#    Updated: 2015/01/11 20:21:36 by vrey             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = g++

NAME = ft_retro

SRC = \
		src/main.cpp \
		src/AEntity.class.cpp \
		src/Enemy.class.cpp \
		src/Game.class.cpp \
		src/Map.class.cpp \
		src/Player.class.cpp \
		src/Pos.class.cpp \
		src/Projectile.class.cpp \
		src/Square.class.cpp

INCL = include/ -lncurses

OBJ = $(SRC:.cpp=.opp)

CFLAGS = -Wall -Werror -Wextra -ansi -Wpedantic -Weffc++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -I $(INCL)

%.opp: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCL)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
