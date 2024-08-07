# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 13:07:55 by joao-pol          #+#    #+#              #
#    Updated: 2024/08/07 00:27:40 by joao-pol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @cc -Wall -Wextra -Werror
NAME = fractol
MLXFLAGS = -Ofast -Lminilibx-linux -lm -lmlx -lX11 -lXext

SRCS = events.c fractol.h help.c main.c math.c math_2.c rendering.c rendering_2.c setup.c string_utils.c

vpath %.c src

OBJS = $(addprefix src/,$(SRCS:.c=.o))


all : $(NAME)

$(NAME) : $(OBJS)
				@make -C minilibx-linux -s 
				@$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean : 
				rm -rf ./src/*.o

fclean : clean
				rm -rf $(NAME)

re : fclean all

mini :
	wget https://cdn.intra.42.fr/document/document/27190/minilibx-linux.tgz
	@tar xf minilibx-linux.tgz
	@rm -fr minilibx-linux.tgz
	@make -C minilibx-linux -s 


debug : CC += -g
debug : re

.PHONY: all clean fclean re mini debug
