//
// Created by Alisa Soroka on 5/19/17.
//

#include "../../rtv1.h"

t_v				*intersect_ray_sphere(t_v *d, t_v *p0, t_sphere *s, double *t)
{

	t_v			*res;
	t_abc		abc;
	t_v			temp_mul;
	t_v			temp_sub;
	t_v			*temp_sub1;


	temp_sub1 = (t_v *)malloc(sizeof(t_v) + 1);
	res = (t_v *)malloc(sizeof(t_v) + 1);
	abc.a = scalar_mult(d, d);
	mult(d, 2, &temp_mul);
	sub(p0, s->center, &temp_sub);
	sub(s->center, p0, temp_sub1);
	abc.b = scalar_mult(&temp_mul, &temp_sub);
	abc.c = scalar_mult(temp_sub1, temp_sub1) - (s->radius * s->radius);
	*t = abc.b * abc.b - 4 * abc.a * abc.c;
	if (*t < 0)
	{
		*t = HUGE;
		return (NULL);
	}
	discriminant(t, abc);
	mult(d, *t, &temp_mul);
	add(&temp_mul, p0, &temp_sub);
//	write(1, "0", 1);
//	normal(&temp_sub, temp_sub1);
	v_copy(res, &temp_sub);
	return (res);
}