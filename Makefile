# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 13:07:55 by joao-pol          #+#    #+#              #
#    Updated: 2024/06/13 15:20:24 by joao-pol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @cc -Wall -Wextra -Werror
NAME = fractol
NAME_BONUS = fractol_bonus
MLXFLAGS = -Ofast -Lminilibx-linux -lm -lmlx -lX11 -lXext

SRCS = main.c rendering.c setup.c events.c string_utils.c  math.c
BSRCS = main_bonus.c rendering_bonus.c rendering_bonus_2.c setup_bonus.c events_bonus.c string_utils.c  math.c math_bonus.c help_bonus.c
vpath %.c src
OBJS = $(addprefix src/,$(SRCS:.c=.o))
BOBJS = $(addprefix src/,$(BSRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
				@make -C minilibx-linux -s 
				@$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS) : $(BOBJS)
				@make -C minilibx-linux -s 
				@$(CC) $(BOBJS) $(MLXFLAGS) -o $(NAME_BONUS)

clean : 
				rm -rf $(OBJS) $(BOBJS)

fclean : clean
				rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS) $(BOBJECTS)

debug : CC += -g
debug : re

.PHONY: all clean fclean re bonus
