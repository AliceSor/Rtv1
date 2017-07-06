//
// Created by Alisa Soroka on 6/29/17.
//

#include "../../rtv1.h"

void 			find_nrml_light_ray(t_v *hit_p, t_v *light_p, t_v *res)
{
	t_v			tmp_sub;
	t_v			tmp_mlt;
	sub(light_p, hit_p, &tmp_sub);
//	sub(hit_p, light_p, &tmp_sub);
	mult(&tmp_sub, -1, &tmp_mlt);
	normal(&tmp_mlt, res);
}