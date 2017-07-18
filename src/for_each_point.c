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

void 			absolute_rotate(t_v *p, t_rt *rt, t_v *res)
{
//	res->x = p->x * cos(G * RAD) * cos(B * RAD) + p->y * sin(G * RAD) * cos(B * RAD) - p->z *sin(G * RAD);
//	res->y = p->x *(cos(G * RAD) * sin (B * RAD) * sin(A * RAD) - sin(G * RAD) * cos(A * RAD)) + p->y * (sin(G * RAD) * sin(A * RAD) * sin (B * RAD) + cos(G * RAD) * cos(A * RAD)) + p->z * cos(B * RAD) * sin(A * RAD);
//	res->z = p->x *(cos(G * RAD) * sin(B * RAD) * cos(A * RAD) - sin(G * RAD) * sin(A * RAD)) + p->y * (sin(G * RAD) * sin(B * RAD) * cos(A * RAD) - cos(G * RAD) * sin(A * RAD)) + p->z * cos(B * RAD) * cos(A * RAD);
	res->x = p->x * cos(G * RAD) * cos(B * RAD) + p->y * (cos(G * RAD) * sin (B * RAD) * sin(A * RAD) - sin(G * RAD) * cos(A * RAD)) + p->z * (cos(G * RAD) * sin(B * RAD) * cos(A * RAD) - sin(G * RAD) * sin(A * RAD));
	res->y = p->x * sin(G * RAD) * cos(B * RAD) + p->y * (sin(G * RAD) * sin(A * RAD) * sin (B * RAD) + cos(G * RAD) * cos(A * RAD)) + p->z * (sin(G * RAD) * sin(B * RAD) * cos(A * RAD) - cos(G * RAD) * sin(A * RAD));
	res->z = p->x * ( - p->z *sin(G * RAD)) + p->y * cos(B * RAD) * sin(A * RAD) + p->z * cos(B * RAD) * cos(A * RAD);
}

void			move_x_point(t_v *p, t_rt *rt)
{
	p->x += 5 * rt->speed_move;
}

void			move_y_point(t_v *p, t_rt *rt)
{
	p->y += 5 * rt->speed_move;
}

void			move_z_point(t_v *p, t_rt *rt)
{
	p->z += 5 * rt->speed_move;
}

void			move_x_point_b(t_v *p, t_rt *rt)
{
	p->x -= 5 * rt->speed_move;
}

void			move_y_point_b(t_v *p, t_rt *rt)
{
	p->y -= 5 * rt->speed_move;
}

void			move_z_point_b(t_v *p, t_rt *rt)
{
	p->z -= 5 * rt->speed_move;
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