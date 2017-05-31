//
// Created by Alisa Soroka on 5/31/17.
//

#include "../../rtv1.h"

t_v         *new_vector(double x, double y, double z)
{
    t_v     *n_v;

    n_v = (t_v *)malloc(sizeof(t_v) + 1);
    if (n_v)
    {
        n_v->x = x;
        n_v->y = y;
        n_v->z = z;
        return (n_v);
    }
    return (NULL);
}