//
// Created by Alisa Soroka on 6/2/17.
//

#include "../../rtv1.h"

void 			for_each_obj(t_rt *rt, void(*f)(t_obj *))
{
	t_obj		*obj;

	obj = rt->obj;
	while (obj)
	{
		obj->f->change_pos = 1;
		(*f)(obj);
		obj = obj->next;
	}
}