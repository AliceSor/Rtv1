# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoroka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 18:13:07 by asoroka           #+#    #+#              #
#    Updated: 2017/05/17 16:41:28 by asoroka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -c -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = rtv1.h

SRC = src/create_win.c			\
	  src/create_image.c 		\
	  src/init_pos_screen.c		\
	  src/put_pixel.c			\
	  src/main.c				\
	  src/v_oper/add.c			\
	  # src/buttons.c				\
	  src/set_limits.c			\
	  src/algoritm.c			\
	  src/zoom.c				\
	  src/set_new_limits.c		\
	  src/create_fractol.c		\
	  src/fractols/julia.c		\
	  src/mouse_move.c			\
	  src/fractols/third_frct.c	\
	  src/fractols/fourth.c		\
	  src/select_frct.c			\
	  src/ft_atoi.c				\
	  src/usage.c				\
	  src/initial_pos.c			\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
		gcc -o $(NAME) $(BINS) $(MLX)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -o $@ $<

clean:
	 /bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
