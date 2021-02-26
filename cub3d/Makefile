.PHONY:		all re clean fclean

CC	 = 	gcc
SRCS =	./main1.c

all:	
		gcc -g -lmlx -framework OpenGL -framework AppKit bonus/main1.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c bonus/parser.c ./cub3d_utils.c parse_mod.c bonus/ft_movement.c ./libft/libft.a; ./a.out map.cub
bonus:
		gcc -g -lmlx -framework OpenGL -framework AppKit ./main1.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c parser/parser.c ./cub3d_utils.c ./parse_mod.c movement/ft_movement.c ./libft/libft.a; ./a.out map.cub