//
// Created by Alisa Soroka on 5/19/17.
//

#include "../../rtv1.h"

void            sub(t_v *v1, t_v *v2, t_v *res)
{
    if (res)
    {
//        write(1, "22\n", 3);

        res->x = v1->x - v2->x;
        res->y = v1->y - v2->y;
        res->z = v1->z - v2->z;
//        printf("(%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", v1->x, v1->y, v1->z, v2->x, v2->y, v2->z, res->x, res->y, res->z);
    }
    /* return (NULL); */
}

