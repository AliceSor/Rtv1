//
// Created by Alisa Soroka on 5/25/17.
//

#include "../../rtv1.h"

static void	  	find(t_abc *abc, t_v *d, t_v *p0, t_cylinder *s)
{
	t_v			delta_p;
	t_v			tmp;
	t_v			sub_1;
	t_v	 		sub_2;
	double		res;

	sub(p0, s->c, &delta_p);
	res = scalar_mult(d, s->n);
	mult(s->n, res, &tmp);
	sub(d, &tmp, &sub_1);
	res = scalar_mult(&delta_p, s->n);
	mult(s->n, res, &tmp);
	sub(&delta_p, &tmp, &sub_2);
	abc->a = scalar_mult(&sub_1,&sub_1);
	abc->b = 2 * scalar_mult(&sub_1, &sub_2);
	abc->c = scalar_mult(&sub_2, &sub_2) - (s->r * s->r);
}

t_v				*intersect_ray_cylinder(t_v *d, t_v *p0, t_cylinder *s, double *t)
{
	t_abc		abc;
	t_v			*res;
	t_v			mlt;
	t_v			temp_add;

//
	find(&abc, d, p0, s);
	discriminant(t, abc);
	res = (t_v *)malloc(sizeof(t_v) + 1);
	if (*t < 0.00f)
	{
		*t = HUGE;
		return (NULL);
	}
	mult(d, *t, &mlt);
	add(&mlt, p0, res);
//	write(1, "2", 1);
//	normal(&temp_add, res);
//	v_copy(res, &temp_add);
	return (res);
}