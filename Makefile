# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpene <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 21:23:37 by cpene             #+#    #+#              #
#    Updated: 2017/09/06 21:30:21 by cpene            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wextra -Wall -Werror

all:
	@gcc $(FLAGS) -c *.c
	@gcc -o $(NAME) *.o

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
