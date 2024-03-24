# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 01:09:42 by orekabe           #+#    #+#              #
#    Updated: 2022/07/03 18:54:30 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

HEADER = -I./include

SRCD = ./src

OBJD = ./objs

SRC = $(SRCD)/bresenham.c $(SRCD)/center.c $(SRCD)/distance.c $(SRCD)/fdf.c $(SRCD)/ft_allocate.c $(SRCD)/ft_atoi.c $(SRCD)/ft_draw_map.c $(SRCD)/ft_fill_data.c $(SRCD)/ft_find_c.c $(SRCD)/ft_free_data.c \
		$(SRCD)/ft_get_line_size.c $(SRCD)/ft_get_lmap.c $(SRCD)/ft_get_map_size.c $(SRCD)/ft_get_win.c $(SRCD)/ft_isdigit.c $(SRCD)/ft_ishexa.c $(SRCD)/ft_put_error.c $(SRCD)/ft_split.c \
		$(SRCD)/ft_strdup.c $(SRCD)/ft_strlen.c $(SRCD)/ft_substr.c $(SRCD)/ft_xtoi.c $(SRCD)/get_next_line_utils.c $(SRCD)/get_next_line.c $(SRCD)/init.c $(SRCD)/iso.c $(SRCD)/my_mlx_pixel_put.c $(SRCD)/rotation.c \
		$(SRCD)/add_to_win.c $(SRCD)/zoom.c $(SRCD)/translate.c $(SRCD)/projection.c $(SRCD)/altitude.c $(SRCD)/rot_hooks.c $(SRCD)/bonus.c
		
OBJ = $(addprefix $(OBJD)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	@printf "                                               \r"
	@echo "	███████╗██████╗ ███████╗"
	@echo "	██╔════╝██╔══██╗██╔════╝"
	@echo "	█████╗  ██║  ██║█████╗  "
	@echo "	██╔══╝  ██║  ██║██╔══╝  "
	@echo "	██║     ██████╔╝██║     "
	@echo "	╚═╝     ╚═════╝ ╚═╝     "
	@echo "		BY: MTRX"
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $@

$(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(OBJD)
	@printf "                                               \r"
	@printf "Compiling $<\r"
	@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@

clean:
	rm -rf $(OBJD)

fclean: clean
	rm -rf $(NAME)

re: fclean all
     