# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 01:09:42 by orekabe           #+#    #+#              #
#    Updated: 2022/07/02 04:43:20 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

HEADER = fdf.h

SRC = bresenham.c center.c distance.c fdf.c ft_allocate.c ft_atoi.c ft_draw_map.c ft_fill_data.c ft_find_c.c ft_free_data.c \
		ft_get_line_size.c ft_get_lmap.c ft_get_map_size.c ft_get_win.c ft_isdigit.c ft_ishexa.c ft_put_error.c ft_split.c \
		ft_strdup.c ft_strlen.c ft_substr.c ft_xtoi.c get_next_line_utils.c get_next_line.c init.c iso.c my_mlx_pixel_put.c rotation.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all