//
// Created by Alisa Soroka on 7/11/17.
//

#include "../../rtv1.h"

void 			move_y(int keycode, t_rt *rt)
{
	if (keycode == 1)
	{
		rt->lights->l->c->y -= 5 * rt->speed_move;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 13)
	{
		rt->lights->l->c->y += 5 * rt->speed_move;
		rt->lights->f->l_change_pos = 1;
		put_image(rt);
		rt->lights->f->l_change_pos = 0;
	}
	else if (keycode == 16)
	{
		B  += 2 * rt->speed_rotate;
		rt->costul = 2;
//		printf("%f \n", A);
//		for_each_dir(rt, rotate_x_point);
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
//		for_each_obj(rt, change_pos);
		put_image(rt);
//		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
	}
	else if (keycode == 32)
	{
		B  -= 2 * rt->speed_rotate;
		rt->costul = 2;
//		printf("%f \n", A);
//		for_each_dir(rt, rotate_x_point);
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
//		for_each_obj(rt, change_pos);
		put_image(rt);
//		fill_directions(rt->screen->r_points, rt->screen->directions, rt->screen, rt);
	}
	else if (keycode == 89)
	{
		for_each_point(rt, move_y_point_b);
		put_image(rt);
//		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
	}
	else if (keycode == 83)
	{
		for_each_point(rt, move_y_point);
		put_image(rt);
//		fill_directions(rt->screen->points, rt->screen->directions, rt->screen, rt);
	}
}