//
// Created by Alisa Soroka on 5/19/17.
//

#include "../../rtv1.h"

t_v             *intersect_ray_sphere(t_v *d, t_v *p0, t_sphere *s, double *t)
{

    t_v         *res;
    t_abc       abc;

    abc.a = scalar_mult(d, d);
    abc.b = scalar_mult(mult(d, 2), sub(p0, s->center));
    abc.c = scalar_mult(sub(s->center, p0), sub(s->center, p0)) - (s->radius * s->radius);
    *t = abc.b * abc.b - 4 * abc.a * abc.c;
    if (*t < 0)
        return (NULL);
    discriminant(t, abc);
    res = normal(add(mult(d, *t), p0));
    return (res);

}