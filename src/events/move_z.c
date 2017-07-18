//
// Created by Alisa Soroka on 7/11/17.
//

#include "../../rtv1.h"

void 			move_z(int keycode, t_rt *rt)
{
	if (keycode == 116)
	{
		rt->lights->l->c->z += 5 * rt->speed_move;
		rt->l_sphere->s->center->z += 5 * rt->speed_move;
		put_image(rt);
	}
	else if (keycode == 121)
	{
		rt->lights->l->c->z -= 5 * rt->speed_move;
		rt->l_sphere->s->center->z -= 5 * rt->speed_move;
		put_image(rt);
	}
	else if (keycode == 91)
	{
		for_each_point(rt, move_z_point);
		put_image(rt);
	}
	else if (keycode == 84)
	{
		for_each_point(rt, move_z_point_b);
		put_image(rt);
	}
	else if (keycode == 6)
	{
		G  += 2 * rt->speed_rotate;
		rt->costul = 3;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
		put_image(rt);
	}
	else if (keycode == 261)
	{
		G  -= 2 * rt->speed_rotate;
		rt->costul = 3;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
		put_image(rt);
	}
}