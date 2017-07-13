//
// Created by Alisa Soroka on 7/11/17.
//

#include "../../rtv1.h"

void 			move_z(int keycode, t_rt *rt)
{
	if (keycode == 116)
	{
		rt->lights->l->c->z += 500;
		put_image(rt);
	}
	else if (keycode == 121)
	{
		rt->lights->l->c->z -= 500;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 91)
	{
		for_each_point(rt, move_z_point);
		put_image(rt);
//		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
	}
	else if (keycode == 84)
	{
		for_each_point(rt, move_z_point_b);
		put_image(rt);
//		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
	}
	else if (keycode == 6)
	{
		G  += 2 * rt->speed_rotate;
		rt->costul = 3;
//		printf("%f \n", A);
//		for_each_dir(rt, rotate_x_point);
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
//		for_each_obj(rt, change_pos);
		put_image(rt);
//		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
	}
	else if (keycode == 261)
	{
		G  -= 2 * rt->speed_rotate;
		rt->costul = 3;
//		printf("%f \n", A);
//		for_each_dir(rt, rotate_x_point);
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
//		for_each_obj(rt, change_pos);
		put_image(rt);
//		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
	}
}