# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 11:23:46 by vkurkela          #+#    #+#              #
#    Updated: 2020/03/15 15:11:44 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = calculator

SRC = calculator.c print_result.c read_input.c

OBJ = $(SRC:.c=.o)

HEADERS = calculator.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I$(HEADERS) -o $@ -c $<

$(LIBFT):
	@${MAKE} -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	mkdir -p obj
	mv $(OBJ) ./obj

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -Rf obj
	@${MAKE} -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean

re: fclean all

.PHONY: all clean fclean re