//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

t_v				*division(t_v *v1, double d)
{
    t_v			*res;


    res = (t_v *)malloc(sizeof(t_v) + 1);
    if (res)
    {
//        write(1, "22\n", 3);

        res->x = v1->x / d;
        res->y = v1->y / d;
        res->z = v1->z / d;
//        printf("(%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", v1->x, v1->y, v1->z, v2->x, v2->y, v2->z, res->x, res->y, res->z);
        return (res);
    }
    /* return (NULL); */
    exit(1);
}
