//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

t_v				*normal(t_v *v1)
{
    t_v			*res;


    res = (t_v *)malloc(sizeof(t_v) + 1);
    if (res)
    {
//        write(1, "22\n", 3);

        res = division(v1, module(v1));
//        printf("(%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", v1->x, v1->y, v1->z, v2->x, v2->y, v2->z, res->x, res->y, res->z);
        return (res);
    }
    /* return (NULL); */
    exit(1);
}
