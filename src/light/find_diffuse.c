//
// Created by Alisa Soroka on 6/29/17.
//

#include "../../rtv1.h"

static void		normal_cylinder(t_obj *obj, t_v *hit_p, t_v *res)
{
	t_v a,b,temp;
	sub(hit_p, obj->cl->c, &b);
	mult(obj->cl->n, scalar_mult(&b, obj->cl->n), &a);
	sub(&a, &b, &temp);
	normal(&temp, res);
}

static void		normal_cone(t_obj *obj, t_v *hit_p, t_v *res)
{
	double 		m;
	t_v			c_h;
	t_v			temp_mult;
	t_v			temp_sub;

	sub(hit_p, obj->cn->c, &c_h);
	m = sqrt(obj->cn->cos_a) * module(&c_h);
	mult(obj->cn->n, m, &temp_mult);
	sub(&temp_mult, &c_h, &temp_sub);
	normal(&temp_sub, res);
}

void			find_normal(t_obj *obj, t_v *hit_p, t_v *res)
{
	t_v			temp;

	if (obj->type_obj == 1)
		normal(obj->p->n, res);
	if (obj->type_obj == 0)
	{
		sub(obj->s->center, hit_p, &temp);
		normal(&temp, res);
	}
	if (obj->type_obj == 2)
		normal_cylinder(obj, hit_p, res);
	if (obj->type_obj == 3)
		normal_cone(obj, hit_p, res);
}

 double 		find_diffuse(t_obj *obj, t_v *hit_p, t_v *light_ray)
{
	t_v			*nrml;
	t_v			temp;
	double 		diffuse;

	nrml = (t_v *)malloc(sizeof(t_v) + 1);
//	if (obj->type_obj == 1)
//	{
//		nrml = obj->p->n;
//		diffuse = scalar_mult(nrml, light_ray);
//		if (diffuse < 0.0f)
//			mult(nrml, -1, &temp);
//		diffuse = scalar_mult(&temp, light_ray);
//		if (diffuse < 0.0f)
//			diffuse = 0.0f;
//	}
//	else
//	{
		find_normal(obj, hit_p, nrml);
		diffuse = scalar_mult(nrml, light_ray);
		if (diffuse < 0.0f)
			diffuse = 0.0f;
//	}
	return (diffuse);
}