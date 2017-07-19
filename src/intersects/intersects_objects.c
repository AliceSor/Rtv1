/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:00:46 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 17:00:49 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

int				intersect_sphere(t_v *d, t_v *p0, t_sphere *s, double *t)
{
	t_abc		abc;
	double		disc;
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

int				intersect_plane(t_v *d, t_v *p0, t_plane *p, double *t)
{
	double		temp;
	double		temp1;

	if ((temp = scalar_mult(d, p->n)) == 0.00f)
	{
		*t = HUGE;
		return (0);
	}
	temp1 = p->dist - scalar_mult(p->n, p0);
	*t = temp1 / temp;
	if (*t < 0)
	{
		*t = HUGE;
		return (0);
	}
	return (1);
}

int				intersect_cylinder(t_v *d, t_v *p0, t_cylinder *s, double *t)
{
	t_abc		abc;

	calc_cylinder(&abc, d, p0, s);
	return (discriminant(t, abc));
}

int				intersect_cone(t_v *d, t_v *p0, t_cone *cn, double *t)
{
	t_abc		abc;

	calc_cone(&abc, d, p0, cn);
	return (discriminant(t, abc));
}
