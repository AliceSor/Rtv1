//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

double				module(t_v *v)
{
    double			res;

	res = 0;
    if (v)
		res = sqrt(scalar_mult(v, v));
    return (res);
}