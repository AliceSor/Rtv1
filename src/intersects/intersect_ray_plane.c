//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

t_v             *intersect_ray_plane(t_v *d,t_v *p0, t_plane *plane, double *t)
{
    t_v         *res;
    double      temp;

    if ((temp = scalar_mult(d, plane->n)) == 0)
        res = NULL;
    else
    {
        *t = (scalar_mult(plane->n, p0) - scalar_mult(plane->c, plane->n)) / temp;
        res = add(mult(d, *t), p0);
    }
    return (res);
}