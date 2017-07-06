//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

void				put_image(t_rt *rt)
{
	mlx_clear_window(rt->mlx->mlx, rt->mlx->win);
	mlx_destroy_image(rt->mlx->mlx, rt->mlx->im);
	create_image(rt->mlx);
	ray_trace(rt);
//	emit_rays(rt);
	mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->im, 0, 0);
}


int					destroy(void)
{
    exit(0);
}

int					buttons(int keycode, t_rt *rt)
{
	if (keycode == 115)
	{
		rt->chosen->f->chosen = 0;

		rt->chosen = (rt->chosen->next) ? rt->chosen->next : rt->obj;
		rt->chosen->f->chosen = 1;

		printf("%d", rt->chosen->type_obj);
		put_image(rt);
	}
	else if (rt->chosen->type_obj == 0)
		move_sphere(keycode, rt);
	else if (rt->chosen->type_obj == 1)
		move_plane(keycode, rt);
	else if (rt->chosen->type_obj == 2)
		move_cylinder(keycode, rt);
	else if (rt->chosen->type_obj == 3)
		move_cone(keycode, rt);

	else if (keycode == 116)
	{
		rt->lights->l->c->z += 100;
		put_image(rt);
	}
	else if (keycode == 121)
	{
		rt->lights->l->c->z -= 100;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 0)
	{
		rt->lights->l->c->x -= 100;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 2)
	{
		rt->lights->l->c->x += 100;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 1)
	{
		rt->lights->l->c->y -= 100;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 13)
	{
		rt->lights->l->c->y += 100;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	if (keycode == 7 && A < 40)
	{
		A  += 1;
//		for_each_point(rt, rotate_x_point);
		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
		for_each_obj(rt, change_pos);
		put_image(rt);
	}
	if (keycode == 16 && B < 40)
	{
		B  += 1;
//		for_each_point(rt, rotate_y_point);
		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
		for_each_obj(rt, change_pos);
		put_image(rt);
	}
	else if (keycode == 91)
	{
		for_each_point(rt, move_z_point);
		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
		for_each_obj(rt, change_pos);
		put_image(rt);
	}

	else if (keycode == 53)
		exit(0);
	return (0);

}


