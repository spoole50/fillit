# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoole <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 17:48:34 by spoole            #+#    #+#              #
#    Updated: 2019/03/01 23:55:26 by spoole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = main.c open.c t_cord_funcs.c t_board_funcs.c solve.c iter.c validate.c
CFLAGS = -Wall -Werror -Wextra
OBJ = $(FILES:.c=.o)

all : $(NAME)

libft: 
	@make -C Libft/ all

$(NAME): libft
	@gcc $(CFLAGS) -c $(FILES)
	@gcc  $(CFLAGS) -o $(NAME)  -I Libft/ -L Libft/ -lft $(OBJ)

clean:
	@rm -f *.o
	@make -C Libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C Libft/ fclean

re: fclean all

.PHONY: all libft $(NAME) clean fclean re
