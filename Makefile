#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 01:16:19 by smaksymy          #+#    #+#              #
#    Updated: 2017/10/17 17:07:37 by smaksymy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fractol

SRC    = src/main.c \
	src/b_ship.c \
	src/b_tree.c \
    src/bio.c \
    src/error.c \
    src/info.c \
    src/julia.c \
    src/line.c \
    src/make.c \
    src/mandel.c \
    src/newton.c \
    src/rot.c \
    src/spider.c \
	src/ui.c

SUBMAKE = ./libft

CD = cd ..

MAKE = make

OBJECT = $(SRC:.c=.o)

CC  = gcc

FLAGS   = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

LIB = -L./libft -lft -I.

all : $(NAME)

$(NAME): $(OBJECT)
	cd $(SUBMAKE) && $(MAKE) && $(CD)
	$(CC) $(FLAGS) -o $(NAME) $(MLX_FLAGS) $(OBJECT) $(LIB)

clean :
	rm -rf src/*.o
	rm -rf libft/*.o

fclean : clean
	rm -rf fractol
	rm -rf libft/libft.a

re : fclean all