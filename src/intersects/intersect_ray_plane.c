//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

t_v				*intersect_ray_plane(t_v *d,t_v *p0, t_plane *p, double *t)
{
	t_v			*res;
	double	  	temp;
	double 		temp1;
	t_v			*tmp;
	t_v			*tmp1;
//
	tmp1 = (t_v *)malloc(sizeof(t_v) + 1);
	tmp = (t_v *)malloc(sizeof(t_v) + 1);
	res = (t_v *)malloc(sizeof(t_v) + 1);
	if ((temp = scalar_mult(d, p->n)) == 0.00f)
	{
		res = NULL;
		*t = HUGE;
	}
	else
	{
		temp1 = p->dist - scalar_mult(p->n, p0);
		*t = temp1 / temp;
//	*t = -((scalar_mult(plane->n, p0) + scalar_mult(plane->c, plane->n)) / temp);
		mult(d, *t, tmp);
		add(tmp, p0, tmp1);
		res = tmp1;
//		write(1, "1", 1);
	}
	return (res);
}