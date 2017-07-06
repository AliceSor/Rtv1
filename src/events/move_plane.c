//
// Created by Alisa Soroka on 6/12/17.
//

#include "../../rtv1.h"

void 		move_plane(int keycode, t_rt *rt)
{
	if (keycode == 78)
    {
		rt->chosen->p->dist += 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
    if (keycode == 69)
    {
		rt->chosen->p->dist -= 100;
		rt->chosen->f->change_pos = 0;
		put_image(rt);
		rt->chosen->f->change_pos = 1;
    }
}
