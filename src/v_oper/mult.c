//
// Created by Alisa Soroka on 5/19/17.
//

#include "../../rtv1.h"

t_v				*mult(t_v *v1, double n)
{
    t_v			*res;

    res = (t_v *)malloc(sizeof(t_v) + 1);
    if (res)
    {
        res->x = v1->x * n;
        res->y = v1->y * n;
        res->z = v1->z * n;
//		printf("(%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", v1->x, v1->y, v1->z, v2->x, v2->y, v2->z, res->x, res->y, res->z);
        return (res);
    }
    /* return (NULL); */
    exit(1);
}