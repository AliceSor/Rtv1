//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

void				normal(t_v *v1, t_v *res)
{
//    t_v			temp;
    if (res && v1)
    {
//        write(1, "22\n", 3);
//		temp.x = v1->x;
//		temp.y = v1->y;
//		temp.z = v1->z;
//        division(&temp, module(&temp), res);
		division(v1, module(v1), res);
//        printf("(%f, %f, %f) + (%f, %f, %f) = (%f, %f, %f)\n", v1->x, v1->y, v1->z, v2->x, v2->y, v2->z, res->x, res->y, res->z);
    }
    /* return (NULL); */
}
