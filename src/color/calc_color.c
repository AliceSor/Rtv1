//
// Created by Alisa Soroka on 7/3/17.
//

#include "../../rtv1.h"

int 				calc_color(t_obj *obj, double diffuse, int is_shadow, double specular)
{
	double 		r;
	double	 	g;
	double 		b;
	int 		res;
	double 		coef;

	double s;
	s = diffuse + pow(diffuse, 300);
	if (obj->f->chosen == 1)
	{
		coef = s * diffuse * 70 * is_shadow + is_shadow * 10 * diffuse + 10;
		r = obj->color->r * coef;
		g = obj->color->g * coef;
		b = obj->color->b * coef;
	}
	else
	{
//		coef = diffuse * 30  +  specular * 30 + 5 + is_shadow * 20;
		coef = s * diffuse * 50 * is_shadow + is_shadow * 10 * diffuse + 5;
		r = obj->color->r * coef;
		g = obj->color->g * coef;
		b = obj->color->b * coef;
	}
	res = integrate_color(r, g, b);
	return (res);
}