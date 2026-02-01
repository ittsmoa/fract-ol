# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 18:43:03 by moatieh           #+#    #+#              #
#    Updated: 2026/01/31 18:43:03 by moatieh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      core.c \
      utils.c \
      view.c \
      mathset.c \
      colors.c \
      events.c

OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
SYS_LIB = -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(SYS_LIB) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
