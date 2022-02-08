# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsellars <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:33:25 by jsellars          #+#    #+#              #
#    Updated: 2022/02/08 16:37:25 by jsellars         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = push_swap.c rules.c  
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = ./includes/

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) libft
	$(CC) -o $@ $< -I$(INCLUDES) -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft bonus

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f push_swap libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
