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
	move_x(keycode, rt);
	move_y(keycode, rt);
	move_z(keycode, rt);
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

	else if (keycode == 92)
	{
		rt->speed_move += 10;
	}
	else if (keycode == 85)
	{
		rt->speed_move -= 10;
	}
	else if (keycode == 82)
	{
		rt->speed_rotate -= 5;
	}
	else if (keycode == 65)
	{
		rt->speed_rotate += 5;
	}
	else if (keycode == 53)
		exit(0);
	return (0);

}


