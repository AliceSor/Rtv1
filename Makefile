# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoroka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 18:13:07 by asoroka           #+#    #+#              #
#    Updated: 2017/07/18 19:48:30 by asoroka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -c# -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = rtv1.h

SRC = src/main.c					 	\
	src/create_image.c					\
	src/create_win.c					\
	src/init_pos_screen.c				\
	src/put_pixel.c						\
	src/v_oper/add.c					\
	src/v_oper/sub.c					\
	src/v_oper/scalar_mult.c			\
	src/v_oper/mult.c					\
	src/v_oper/div.c					\
	src/v_oper/module.c					\
	src/v_oper/normal.c					\
	src/v_oper/v_copy.c					\
	src/v_oper/new_vector.c				\
	src/events/buttons.c				\
	src/intersects/intersect.c			\
	src/intersects/intersect_ray_sphere.c	\
	src/intersects/intersect_ray_plane.c	\
	src/intersects/intersect_ray_cylinder.c\
	src/discriminant.c	\
	src/objects/create_obj.c	\
	src/objects/create_sphere.c		\
	src/objects/create_plane.c		\
	src/objects/create_cylinder.c		\
	src/objects/fill_objects.c		\
	src/v_oper/compare.c				\
	src/objects/for_each_obj.c			\
	src/events/change_pos.c				\
	src/intersects/intersect_cone.c		\
	src/objects/create_cone.c			\
	src/events/move_plane.c				\
	src/events/move_sphere.c			\
	src/events/move_cylinder.c			\
	src/events/move_cone.c				\
	src/objects/create_light.c			\
	src/b_zero.c						\
	src/pull_color.c					\
	src/color/integrate_color.c			\
	src/color/create_color.c			\
	src/for_each_point.c				\
	src/ray_trace.c						\
	src/intersects/intersects_objects.c	\
	src/intersects/some_calculating.c	\
	src/intersects/identify_obj.c		\
	src/intersects/find_hit_point.c		\
	src/intersects/find_nrml_light_ray.c\
	src/light/find_diffuse.c			\
	src/color/calc_color.c				\
	src/light/find_specular.c			\
	src/events/move_x.c					\
	src/events/move_y.c					\
	src/events/move_z.c					\
	src/events/change_size.c			\

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
