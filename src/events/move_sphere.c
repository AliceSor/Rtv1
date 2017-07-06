//
// Created by Alisa Soroka on 6/12/17.
//

#include "../../rtv1.h"

void 			move_sphere(int keycode, t_rt *rt)
{
	if (keycode == 123)
	{
		rt->chosen->s->center->x -= 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
	}
    if (keycode == 124)
    {
		rt->chosen->s->center->x += 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
    if (keycode == 126)
    {
		rt->chosen->s->center->y -= 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
    if (keycode == 125)
	{
		rt->chosen->s->center->y += 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
    if (keycode == 78)
    {
		rt->chosen->s->center->z += 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
    if (keycode == 69)
    {
		rt->chosen->s->center->z -= 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
}