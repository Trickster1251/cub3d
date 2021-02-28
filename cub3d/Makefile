.PHONY:		all re clean fclean

CC	 = 	gcc
SRCS =	*.c
OBJT =	$(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all:	
			gcc -lmlx -framework OpenGL -framework AppKit -c $(SRCS);
			$(CC) -lmlx -framework OpenGL -framework AppKit -o cub3D *.o $(LIBFT);
