//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

void            v_copy(t_v *dest, t_v *src)
{
    src->x = dest->x;
    src->y = dest->y;
    src->z = dest->z;
}