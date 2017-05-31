//
// Created by Alisa Soroka on 5/31/17.
//

#include "../../rtv1.h"

void 			fill_objects(t_rt *rt)
{
	t_obj		*obj_p;
	t_obj		*obj_s;
	t_obj		*obj_cl;

	rt->obj = create_obj(1);
	rt->obj->p = create_plane(new_vector(500, 400, 100), new_vector(0, 2, 1), 0xFFFFFF);
	obj_p = create_obj(1);
	obj_p->p = create_plane(new_vector(500, 400, 100), new_vector(0, -2, 1), 0x00FFFF);
	add_obj(rt->obj, obj_p);
//	free(obj);
	obj_s = create_obj(0);
	obj_s->s = create_sphere(new_vector(200, 400, 0));
	add_obj(rt->obj, obj_s);
//	free(obj);
	obj_cl = create_obj(2);
	obj_cl->cl = create_cylinder(new_vector(500, 400, 10), new_vector(0, 0, 1), 0xFF);
	add_obj(rt->obj, obj_cl);
}
