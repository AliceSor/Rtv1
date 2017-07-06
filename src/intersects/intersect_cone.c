//
// Created by Alisa Soroka on 6/2/17.
//

#include "../../rtv1.h"

static void      find(t_abc *abc, t_v *d, t_v *p0, t_cone *cn)
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

//	t_v			*d_p;
//	t_v			*m_n_d_n;
//	t_v			*m_n_d_p_n;
//	t_v			*sub_d_ndn;
//	t_v			*sub_some_shit;
//	double 		d_n;
//	double 		d_p_n;
//
//	d_p = (t_v *)malloc(sizeof(t_v) + 1);
//	m_n_d_n = (t_v *)malloc(sizeof(t_v) + 1);
//	m_n_d_p_n = (t_v *)malloc(sizeof(t_v) + 1);
//	sub_d_ndn = (t_v *)malloc(sizeof(t_v) + 1);
//	sub_some_shit = (t_v *)malloc(sizeof(t_v) + 1);
//	sub(p0, cn->c, d_p);
//	d_n = scalar_mult(d, cn->n);
//	d_p_n = scalar_mult(d_p, cn->n);
//	mult(cn->n, d_n, m_n_d_n);
//	mult(cn->n,d_p_n, m_n_d_p_n);
//	sub(d, m_n_d_n, sub_d_ndn);
//	sub(d_p, m_n_d_p_n, sub_some_shit);
//	abc->a = cn->cos_a * scalar_mult(sub_d_ndn, sub_d_ndn) -cn->sin_a * d_n * d_n;
//	abc->b = cn->cos_a2 * scalar_mult(sub_d_ndn, sub_d_ndn) - cn->sin_a2 * d_n * scalar_mult(d_p,cn->n);
//	abc->c = cn->cos_a * scalar_mult(sub_some_shit, sub_some_shit) - cn->sin_a * d_p_n * d_p_n;
}

t_v             *intersect_ray_cone(t_v *d, t_v *p0, t_cone *cn, double *t)
{
	t_abc       *abc;
	t_v         *res;
	t_v			*mlt;
//	t_v			*temp_add;
	int 		k;

	abc = (t_abc *)malloc(sizeof(t_abc) +1);
	res = (t_v *)malloc(sizeof(t_v) + 1);
	mlt = (t_v *)malloc(sizeof(t_v) + 1);
//	temp_add = (t_v *)malloc(sizeof(t_v) + 1);
	find(abc, d, p0, cn);
	k = discriminant(t, *abc);
//	if (k == 0) {
//		return (NULL);
//	}
	if (*t < 0)
	{
		*t = HUGE;
		return (NULL);
	}
	mult(d, *t, mlt);
	add(mlt, p0, res);
//	write(1, "3", 1);
//	v_copy(res, temp_add);
//	normal(&temp_add, res);
	return (res);
}