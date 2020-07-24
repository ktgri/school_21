# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 21:24:54 by bmahi             #+#    #+#              #
#    Updated: 2019/04/09 21:26:27 by bmahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
all: $(NAME)
$(NAME):
	gcc -c -Wextra -Wall -Werror ft_display_file.c
	gcc -o $(NAME) ft_display_file.o
clean:
	/bin/rm -f ft_display_file.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
