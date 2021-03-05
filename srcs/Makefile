# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walethea <walethea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 00:30:56 by walethea          #+#    #+#              #
#    Updated: 2021/03/05 20:56:57 by walethea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
INCLUDES =  ./cub3d.h
SRCS	=	../get_next_line/get_next_line.c\
			../get_next_line/get_next_line_utils.c\
			./cast_sprite/cast_sprite.c\
			./cast_sprite/cast_sprite_utils.c\
			./movement/key_hook_utils.c\
			./parser/ft_atoi_colon.c\
			./parser/parse_mod.c\
			./parser/parse_color.c\
			./parser/parse_textures.c\
			./parser/parser.c\
			./parser/parser_utils.c\
			./parser/parser_utils_2.c\
			./parser/parser_utils_3.c\
			./raycast/ft_screenshot.c\
			./raycast/image_utils.c\
			./raycast/raycaster_utils.c\
			./main.c \

BONUS_SRCS	=	./bonus/ft_movement_bonus.c\
				./bonus/raycaster_bonus.c\

MAIN_SRCS	= 	./raycast/raycaster.c\
				./movement/ft_movement.c\

				
FLAGS	=	-Wall -Wextra -Werror
FRAMEWORK	= -L ../minilibx_opengl/ -lmlx -framework OpenGL -framework AppKit
FRAMEWORK1	= -L ../minilibx_mms/ -lmlx -framework OpenGL -framework AppKit
LIBFT	=	 -L../libft -lft
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
		@echo "------------>Please wait, minilibx compile...<------------"
		@make re -C ../libft;
		@make bonus -C ../libft;
		@make -C../minilibx_opengl;
		@make -C../minilibx_mms;
		@cp ../minilibx_mms/libmlx.dylib ./
		@gcc -g $(FLAGS) $(SRCS) $(MAIN_SRCS) $(LIBFT) $(FRAMEWORK) libmlx.dylib -o $(NAME)
		@echo "------------>SUCCESS<------------"

a:		
		gcc -g $(FLAGS) $(SRCS) $(MAIN_SRCS) $(LIBFT) $(FRAMEWORK) libmlx.dylib -o $(NAME)

bonus:	$(BONUS_OBJS)
		@gcc $(FLAGS) $(SRCS) $(BONUS_SRCS) $(LIBFT) $(FRAMEWORK) -o $(NAME)
		@echo "------------>SUCCESS<------------"

clean:	
		@make clean -C ../libft
		@make clean -C../minilibx_opengl
		@rm -rf $(OBJS)
		@rm -rf $(BONUS_OBJS)
		@rm -f libmlx.dylib
		@rm -rf cub3D.dSYM
		@rm -f screenshot.bmp
		@echo "------------>Delete all .o files<------------>"

fclean:	clean
		@make fclean -C../libft
		@rm -f $(NAME)
		@echo "------------>Delete all .o files and ./cub3D<------------>"
re:		fclean $(NAME) all

.PHONY:		all clean fclean re