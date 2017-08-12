/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:51:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/22 14:16:19 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void				put_image(t_rt *rt)
{
	mlx_clear_window(rt->mlx->mlx, rt->mlx->win);
	mlx_destroy_image(rt->mlx->mlx, rt->mlx->im);
	create_image(rt->mlx);
	ray_trace(rt);
	mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->im, 0, 0);
}

int					destroy(void)
{
	exit(0);
}

static void			for_chosen_objects(int keycode, t_rt *rt)
{
	if (rt->chosen->type_obj == 0)
	{
		move_sphere(keycode, rt);
		change_size(keycode, rt);
	}
	else if (rt->chosen->type_obj == 1)
		move_plane(keycode, rt);
	else if (rt->chosen->type_obj == 2)
	{
		move_cylinder(keycode, rt);
		change_size(keycode, rt);
	}
	else if (rt->chosen->type_obj == 3)
		move_cone(keycode, rt);
}

static void			for_chosen(int keycode, t_rt *rt)
{
	if (keycode == 115)
	{
		rt->chosen->f->chosen = 0;
		rt->chosen = (rt->chosen->next) ? rt->chosen->next : rt->obj;
		rt->chosen->f->chosen = 1;
		if (rt->chosen->f->for_light)
		{
			rt->chosen->f->chosen = 0;
			rt->chosen = (rt->chosen->next) ? rt->chosen->next : rt->obj;
			rt->chosen->f->chosen = 1;
		}
	}
	if (keycode == 51)
		rt->chosen->f->is_visible = (rt->chosen->f->is_visible) ? 0 : 1;
}

int					buttons(int keycode, t_rt *rt)
{
	move_x(keycode, rt);
	move_y(keycode, rt);
	move_z(keycode, rt);
	for_chosen(keycode, rt);
	for_chosen_objects(keycode, rt);
	if (keycode == 49)
		rt->is_light = (rt->is_light) ? 0 : 1;
	simple_move(keycode, rt);
	put_image(rt);
	change_speed(keycode, rt);
	if (keycode == 53)
		exit(0);
	put_image(rt);
	return (0);
}
