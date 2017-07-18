//
// Created by Alisa Soroka on 6/12/17.
//

#include "../../rtv1.h"

void 			move_cone(int keycode, t_rt *rt)
{
	if (keycode == 123)
		rt->chosen->cn->c->x -= 100;
	else if (keycode == 124)
		rt->chosen->cn->c->x += 100;
	else if (keycode == 126)
		rt->chosen->cn->c->y -= 100;
	else if (keycode == 125)
		rt->chosen->cn->c->y += 100;
	else if (keycode == 78)
		rt->chosen->cn->c->z += 100;
	else if (keycode == 69)
		rt->chosen->cn->c->z -= 100;
}
