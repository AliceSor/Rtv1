//
// Created by Alisa Soroka on 5/19/17.
//

#include "../../rtv1.h"

double				scalar_mult(t_v *v1, t_v *v2)
{
    double			res;

    res = (v1->x * v2->x) + v1->y * v2->y + v1->z * v2->z;
//    res += v1->y * v2->y;
//    res += v1->z * v2->z;
    return (res);
}