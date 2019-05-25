# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/18 09:40:57 by lcrawn            #+#    #+#              #
#    Updated: 2019/05/25 15:17:36 by lcrawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/*.c

HDR = header/

LIB = libft/libft.a

all:
	gcc -Wall -Wextra -Werror -o fillit -I $(HDR) $(SRC) -L. $(LIB)

lib:
	cd ./libft && make && make clean

clean:
	rm -f a.out

re: clean all