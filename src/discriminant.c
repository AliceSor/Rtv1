//
// Created by Alisa Soroka on 5/26/17.
//

#include "../rtv1.h"

int	        	discriminant(double *t, t_abc abc)
{
    abc.d = abc.b * abc.b - 4 * abc.a * abc.c;
    if (abc.d < 0.0f)
        return (0);
    abc.c = sqrt(abc.d);
    abc.t0 = (-abc.b + abc.c) / (2 * abc.a);
    abc.t1 = (-abc.b - abc.c) / (2 * abc.a);
    if (abc.t0 < 0.001f && abc.t1 < 0.001f)
        return (0);
    else if (abc.t0 > 0.001f && abc.t1 > 0.001f && abc.t0 > abc.t1)
        abc.t0 = abc.t1;
    else if (abc.t0 < 0.001f)
        abc.t0 = abc.t1;
    if (abc.t0 > 0.001f)
    {
        *t = abc.t0;
        return (1);
    }
    return (0);
}