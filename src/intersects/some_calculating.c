/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_calculating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:03:22 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 17:11:11 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			calc_cone(t_abc *abc, t_v *d, t_v *p0, t_cone *cn)
{
	t_v			mul;
	t_v			dist;
	double		r1;
	double		r2;

	sub(p0, cn->c, &dist);
	r1 = scalar_mult(d, cn->n);
	mult(cn->n, r1, &mul);
	sub(d, &mul, cn->sub_1);
	r2 = scalar_mult(&dist, cn->n);
	mult(cn->n, r2, &mul);
	sub(&dist, &mul, cn->sub_2);
	abc->a = cn->cos_a * scalar_mult(cn->sub_1, cn->sub_1)
		- cn->sin_a * (r1 * r1);
	abc->b = cn->cos_a2 * scalar_mult(cn->sub_1, cn->sub_2)
		- cn->sin_a2 * (r1 * r2);
	abc->c = cn->cos_a * scalar_mult(cn->sub_2, cn->sub_2)
		- cn->sin_a * (r2 * r2);
}

void			calc_cylinder(t_abc *abc, t_v *d, t_v *p0, t_cylinder *s)
{
	t_v			delta_p;
	t_v			tmp;
	t_v			sub_1;
	t_v			sub_2;
	double		res;

	sub(p0, s->c, &delta_p);
	res = scalar_mult(d, s->n);
	mult(s->n, res, &tmp);
	sub(d, &tmp, &sub_1);
	res = scalar_mult(&delta_p, s->n);
	mult(s->n, res, &tmp);
	sub(&delta_p, &tmp, &sub_2);
	abc->a = scalar_mult(&sub_1, &sub_1);
	abc->b = 2 * scalar_mult(&sub_1, &sub_2);
	abc->c = scalar_mult(&sub_2, &sub_2) - (s->r * s->r);
}
