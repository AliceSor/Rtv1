//
// Created by Alisa Soroka on 7/7/17.
//

#include "../../rtv1.h"

double 		find_specular(t_obj *obj, t_v *hit_p, t_v *dir_ray, t_v *light_ray)
{
	t_v			*nrml;
	double 		specular;
	t_v			h;
	t_v			temp_add;

	nrml = (t_v *)malloc(sizeof(t_v) + 1);
	find_normal(obj, hit_p, nrml);
	add(dir_ray, light_ray, &temp_add);
	normal(&temp_add, &h);
	specular = scalar_mult(nrml, &h);
	if (specular < 0.0f)
		specular = 0.0f;
	return (specular);
}