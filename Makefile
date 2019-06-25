# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/18 09:40:57 by lcrawn            #+#    #+#              #
#    Updated: 2019/05/27 16:01:52 by lcrawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/additional.c \
      src/checks.c \
      src/create_list_func.c \
      src/dots_check.c \
      src/main.c \
      src/get_next_line.c \
      src/lists_and_not_only.c \
      src/matrix_func.c \
      src/print.c \
      src/swaps.c \
      src/validation.c

HDR = header/

LIB = libft/

LIBF_A = libft/libft.a

NAME = fillit

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc -Wall -Wextra -Werror $(SRC) -I $(HDR) -o $(NAME) -L. $(LIBF_A)

clean:
	rm -f libft/*.o
	make -C $(LIB) clean

fclean: clean
	rm -f fillit
	make -C $(LIB) fclean

re: fclean all
