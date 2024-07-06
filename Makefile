# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asajid <asajid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 10:46:57 by asajid            #+#    #+#              #
#    Updated: 2024/04/28 10:46:57 by asajid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS    =  init/init_data.c init/init_mlx.c  init/init_texture.c  exit/exit.c \
			exit/free_data.c raycast/draw.c   raycast/raycast.c  main.c \
			parsing/check_border.c \
			parsing/check_file.c \
			parsing/check_map_file.c \
			parsing/check_map.c \
			parsing/create_map.c \
			parsing/floor_ceiling.c \
			parsing/parse_args.c \
			parsing/parsing_utils.c \
			parsing/texture_fc.c \
			raycast/texture.c	\
			movement/input_handler.c \
			movement/player_dir.c \
			movement/player_pos.c \
			movement/player_move.c \
			movement/player_rotate.c \
			error.c


OBJS    = $(SRCS:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -I/usr/include -Imlx -c $< -o $@

$(NAME): $(OBJS)
		@${MAKE} -C ./libft
		$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -lz -o $(NAME) ./libft/libft.a


all: $(NAME)
clean:
		@rm -f $(OBJS)
		@$(MAKE) -C ./libft clean

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C ./libft fclean

re: fclean all
