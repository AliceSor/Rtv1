//
// Created by Alisa Soroka on 6/29/17.
//

#include "../../rtv1.h"

int 				identify_obj(t_v *d, t_v *p0, t_obj *obj, double *t)
{
	if (obj->type_obj == 0)
		return (intersect_sphere(d, p0, obj->s, t));
	if (obj->type_obj == 1)
		return (intersect_plane(d, p0, obj->p, t));
	if (obj->type_obj == 2)
		return (intersect_cylinder(d, p0, obj->cl, t));
	if (obj->type_obj == 3)
		return (intersect_cone(d, p0, obj->cn, t));
	else
		return (0);
}