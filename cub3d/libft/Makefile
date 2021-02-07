# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walethea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 21:26:37 by walethea          #+#    #+#              #
#    Updated: 2021/02/07 11:45:36 by walethea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

SRCS = ft_isalpha.c \
	   ft_memchr.c \
	   ft_putendl_fd.c \
	   ft_strjoin.c \
	   ft_strlen.c \
	   ft_toupper.c \
	   ft_isascii.c \
	   ft_memcmp.c \
	   ft_putnbr_fd.c \
	   ft_strlcat.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_isdigit.c \
	   ft_memcpy.c \
	   ft_putstr_fd.c \
	   ft_strlcpy.c \
	   ft_strrchr.c \
	   ft_bzero.c \
	   ft_isprint.c \
	   ft_memmove.c \
	   ft_split.c \
	   ft_strlen.c \
	   ft_strtrim.c \
	   ft_calloc.c \
	   ft_itoa.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strmapi.c \
	   ft_substr.c \
	   ft_isalnum.c \
	   ft_memccpy.c \
	   ft_putchar_fd.c \
	   ft_strdup.c \
	   ft_strncmp.c \
	   ft_tolower.c

BONUS_SRCS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c
			 
OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "The libriry is successfully created"

.c.o:
	@gcc $(FLAG) -I $(INC) -c $< -o $@

bonus: all $(BONUS_OBJS)
	@ar rc $(NAME) $(BONUS_OBJS)
	@ranlib $(NAME)
	@echo "The library add bonus files"

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -rf $(NAME)
	@echo "All binaries and library have been removed."

re: fclean all

.PHONY: all clean fclean re
