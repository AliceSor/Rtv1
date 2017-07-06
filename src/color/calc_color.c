//
// Created by Alisa Soroka on 7/3/17.
//

#include "../../rtv1.h"

int 			calc_color(t_obj *obj, double diffuse, int is_shadow, double specular)
{
	double 		r;
	double	 	g;
	double 		b;
	int 		res;

	if (obj->f->chosen == 1)
	{
		r = obj->color->r * (diffuse) * 50 + obj->color->r * 20 + is_shadow * 20 * obj->color->r;
		g = obj->color->g * (diffuse) * 50 + obj->color->g * 20 + is_shadow * 20 * obj->color->g;
		b = obj->color->b * (diffuse) * 50 + obj->color->b * 20 + is_shadow * 20 * obj->color->b;
	}
	else
	{
		r = obj->color->r * (diffuse * is_shadow * 50 + 10 + is_shadow * 10);
		g = obj->color->g * (diffuse * is_shadow * 50 + 10 + is_shadow *10);
		b = obj->color->b * (diffuse * is_shadow * 50 + 10 + is_shadow * 10);
	}
	res = integrate_color(r, g, b);
	obj->diffuse = 0;
	return (res);
}