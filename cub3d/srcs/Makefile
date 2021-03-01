# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walethea <walethea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 00:30:56 by walethea          #+#    #+#              #
#    Updated: 2021/03/02 00:44:11 by walethea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
INC = cub3d.h
LIBA = ./libft/libft.a
GCC =	gcc
GNL =	$(GCC) $(FLAG) ./get_next_line\get_next_line.c
		$(GCC) $(FLAG) ./get_next_line\get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
.c.o:
	@gcc $(FLAG) -c $< -o $@
$(NAME): $(OBJS)
	@make re -C libft
	@make bonus -C libft
	@$(GCC) $(FLAG) -lmlx -framework OpenGL -framework AppKit -c main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c parser/parser.c ft_screenshot.c parser/parser_utils_3.c parser/parse_mod.c movement/ft_movement.c cast_sprite.c parser/parser_utils.c movement/key_hook_utils.c parser/parse_textures.c raycaster.c parser/parser_utils_2.c ft_atoi_colon.c cast_sprite_utils.c raycaster_utils.c image_utils.c libft/libft.a;
	@echo "------>cub3D compile!<------";
all: $(NAME)
clean:
	@make clean -C ./libft
	@rm -rf *.o
	@echo "Binaries have been removed"
fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "Libftprint.a and binaries has been removed"
re: fclean all
.PHONY: all clean fclean re