//
// Created by Alisa Soroka on 6/2/17.
//

#include "../../rtv1.h"

double				compare(t_v *v1, t_v *v2)
{
	double			res;

	if (v1->x == v2->x && v1->y == v2->y && v1->z == v2->z)
		res = 0;
	else
		res = 1;
	return (res);
}