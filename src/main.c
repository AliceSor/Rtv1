/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:38:53 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/22 14:27:36 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include <stdio.h>

static int		mouse_func(int keycode, int x, int y, t_rt *rt)
{
	printf("kc: %d, x: %d, y: %d\n", keycode, x, y);
	mlx_string_put(rt->mlx1->mlx, rt->mlx->win, WIDTH + 10, 10, 0xFFFFFF, "Hilgvjndz;vn\n bnvkjdbn \njkdahhs");
	mlx_string_put(rt->mlx1->mlx, rt->mlx->win, WIDTH + 10, 60, 0xFFFFFF, "sdaflknkdsangvka");
	mlx_put_image_to_window(rt->mlx1->mlx, rt->mlx->win, rt->mlx1->im, WIDTH + (x/10), 100000);
	return(0);
}

int				main(void)
{
	t_rt		*rt;

	rt = (t_rt *)malloc(sizeof(t_rt) + 1);
	rt->costul = 0;
	rt->mlx = create_win();
	create_image(rt->mlx, WIDTH, HEIGHT);
	rt->screen = init_pos_screen(rt);
	rt->objects = (t_obj **)malloc(sizeof(t_obj *) * 10 + 1);
	fill_objects(rt);
	rt->chosen = rt->obj;
	rt->chosen->f->chosen = 1;
	rt->speed = 1;
	rt->speed_move = 10;
	rt->speed_rotate = 5;
	rt->is_light = 1;
	rt->hit_point = (t_v *)malloc(sizeof(t_v) + 1);
	rt->light_ray = (t_v *)malloc(sizeof(t_v) + 1);
	rt->temp_sub = (t_v *)malloc(sizeof(t_v) + 1);
	ray_trace(rt);
	mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->im, -1, -1);
	rt->mlx1 = create_mlx();
	create_image(rt->mlx1, SIDEBAR_W, HEIGHT);
	mlx_string_put(rt->mlx1->mlx, rt->mlx->win, WIDTH + 10, 10, 0xFFFFFF, "Hilgvjndz;vn");
	mlx_put_image_to_window(rt->mlx1->mlx, rt->mlx->win, rt->mlx1->im, WIDTH + 10, 100000);
	mlx_hook(rt->mlx->win, 2, 5, buttons, rt);
	mlx_hook(rt->mlx->win, 17, 0, destroy, 0);
	mlx_mouse_hook(rt->mlx->win, mouse_func, rt);
	mlx_loop(rt->mlx->mlx);
	return (0);
}
