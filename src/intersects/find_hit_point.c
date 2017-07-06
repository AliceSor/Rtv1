//
// Created by Alisa Soroka on 6/29/17.
//

#include "../../rtv1.h"

void			find_hit_point(double t, t_v *d, t_v *p0, t_v *res)
{
	t_v 		tmp_mult;

	mult(d, t, &tmp_mult);
	add(&tmp_mult, p0, res);
}