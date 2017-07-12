//
// Created by Alisa Soroka on 6/29/17.
//

#include "../../rtv1.h"

int				intersect_sphere(t_v *d, t_v *p0, t_sphere *s, double *t)
{
	t_abc		abc;
	double 		disc;
	t_v			temp_mul;
	t_v			temp_sub;
	t_v			*temp_sub1;


	temp_sub1 = (t_v *)malloc(sizeof(t_v) + 1);
	abc.a = scalar_mult(d, d);
	mult(d, 2, &temp_mul);
	sub(p0, s->center, &temp_sub);
	sub(s->center, p0, temp_sub1);
	abc.b = scalar_mult(&temp_mul, &temp_sub);
	abc.c = scalar_mult(temp_sub1, temp_sub1) - (s->radius * s->radius);
	disc = abc.b * abc.b - 4 * abc.a * abc.c;
	if (disc > 0.001f && discriminant(t, abc) == 1)
		return (1);
	return (0);
}

int				intersect_plane(t_v *d,t_v *p0, t_plane *p, double *t)
{
	double	  	temp;
	double 		temp1;

	if ((temp = scalar_mult(d, p->n)) == 0.00f)
	{
		*t = HUGE;
		return (0);
	}
	temp1 = p->dist - scalar_mult(p->n, p0);
	*t = temp1 / temp;
	return (1);
}

static void	  	calc_cylinder(t_abc *abc, t_v *d, t_v *p0, t_cylinder *s)
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

int				intersect_cylinder(t_v *d, t_v *p0, t_cylinder *s, double *t)
{
	t_abc		abc;

	calc_cylinder(&abc, d, p0, s);
	return (discriminant(t, abc));
}


static void		calc_cone(t_abc *abc, t_v *d, t_v *p0, t_cone *cn)
{
	t_v			mul;
	t_v			*sub_1;
	t_v			*sub_2;
	t_v			dist;
	double		r1;
	double		r2;

	sub_1 = (t_v *)malloc(sizeof(t_v) + 1);
	sub_2 = (t_v *)malloc(sizeof(t_v) + 1);
	sub(p0, cn->c, &dist);
	r1 = scalar_mult(d, cn->n);
	mult(cn->n, r1, &mul);
	sub(d, &mul, sub_1);
	r2 = scalar_mult(&dist, cn->n);
	mult(cn->n, r2, &mul);
	sub(&dist, &mul, sub_2);
	abc->a = cn->cos_a * scalar_mult(sub_1, sub_1) - cn->sin_a * (r1 * r1);
	abc->b = cn->cos_a2 * scalar_mult(sub_1, sub_2) - cn->sin_a2 * (r1 * r2);
	abc->c = cn->cos_a * scalar_mult(sub_2, sub_2) - cn->sin_a * (r2 * r2);
}

int				intersect_cone(t_v *d, t_v *p0, t_cone *cn, double *t)
{
	t_abc	   *abc;

	abc = (t_abc *)malloc(sizeof(t_abc) +1);
	calc_cone(abc, d, p0, cn);
	return(discriminant(t, *abc));
}