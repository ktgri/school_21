# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 17:07:42 by bmahi             #+#    #+#              #
#    Updated: 2019/06/03 21:14:19 by kcorie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
valid.c \
feel_it.c \
block_gabarites.c \
free_map.c \
solution.c

OBJ = *.o

INCLUDES = fillit.h

LIB = ./libft

CC = @gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIB) re
	$(CC) $(CFLAGS) -L $(LIB) -lft $(SRC) -I $(LIB) -I $(INCLUDES) -o $(NAME) 

clean:
	@make -C $(LIB) clean

fclean: clean
	@make -C $(LIB) fclean
	@/bin/rm -f $(NAME)

re: fclean all
