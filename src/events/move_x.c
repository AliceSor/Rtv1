//
// Created by Alisa Soroka on 7/11/17.
//

#include "../../rtv1.h"

void 			move_x(int keycode, t_rt *rt)
{
	if (keycode == 0)
	{
		rt->lights->l->c->x -= 500;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 2)
	{
		rt->lights->l->c->x += 500;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 7)// && A < 14)
	{
		A  += 2 * rt->speed_rotate;
		rt->costul = 1;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
		put_image(rt);
	}
	else if (keycode == 8)// && A < 14)
	{
		A  -= 2 * rt->speed_rotate;
		rt->costul = 1;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
		put_image(rt);
	}
	else if (keycode == 86)
	{
		for_each_point(rt, move_x_point_b);
		put_image(rt);
	}
	else if (keycode == 88)
	{
		for_each_point(rt, move_x_point);
		put_image(rt);
	}
}