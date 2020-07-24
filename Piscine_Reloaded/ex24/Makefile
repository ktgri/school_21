# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 16:00:30 by bmahi             #+#    #+#              #
#    Updated: 2019/04/08 17:28:53 by bmahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./includes/

SRC = ./srcs/*.c

OSRC = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OSRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
