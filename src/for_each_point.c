//
// Created by Alisa Soroka on 6/22/17.
//

#include "../rtv1.h"

void			rotate_x_point(t_v *p, t_rt *rt, t_v *res)
{
	res->x = p->x;
	res->y = p->y * cos(A * RAD) + p->z * sin(A * RAD);
//	printf("(A = %f) (y = %f)", A, res->y);
	res->z = -p->y * sin(A * RAD) + p->z * cos(A * RAD);
}

void			rotate_y_point(t_v *p, t_rt *rt, t_v *res)
{
	res->x = p->x * cos(B * RAD) + p->z * sin(B * RAD);
	res->z = -p->x * sin(B * RAD) + p->z * cos(B * RAD);
}

void			rotate_z_point(t_v *p, t_rt *rt, t_v *res)
{
	res->x = p->x * cos(G * RAD) - p->y * sin(G * RAD);
	res->y = p->x * sin(G * RAD) + p->y * cos(G * RAD);
}

void			move_x_point(t_v *p, t_rt *rt)
{
	p->x += 1000;
}

void			move_y_point(t_v *p, t_rt *rt)
{
	p->y += 1000;
}

void			move_z_point(t_v *p, t_rt *rt)
{
	p->z += 1000;
}

void			move_x_point_b(t_v *p, t_rt *rt)
{
	p->x -= 1000;
}

void			move_y_point_b(t_v *p, t_rt *rt)
{
	p->y -= 1000;
}

void			move_z_point_b(t_v *p, t_rt *rt)
{
	p->z -= 1000;
}

void 			for_each_point(t_rt *rt, void(*f)(t_v *, t_rt *))
{
	t_v			*p;
	int 		i;
	int 		i_max;

	p = rt->screen->points;
	i = 0;
	i_max = HEIGHT * WIDTH;
	if (p && rt->screen->eye)
	{
		while (i < i_max) {
			(*f)(&(p[i]), rt);
			i++;
		}
		(*f)(rt->screen->eye, rt);
	}
}

void 			for_each_dir(t_rt *rt, void(*f)(t_v *, t_rt *))
{
	t_v			*p;
	int 		i;
	int 		i_max;

	p = rt->screen->directions;
	i = 0;
	i_max = HEIGHT * WIDTH;
	if (p && rt->screen->eye)
	{
		while (i < i_max) {
			(*f)(&(p[i]), rt);
			i++;
		}
//		(*f)(rt->screen->eye, rt);
	}
}