//
// Created by Alisa Soroka on 5/25/17.
//

#include "../../rtv1.h"

static void      find(t_abc *abc, t_v *d, t_v *p0, t_cylinder *s)
{
    t_v	        	*delta_p;
    t_v	        	*tmp;
    t_v	    	    *sub_1;
    t_v     		*sub_2;
    double		res;

    delta_p = sub(p0, s->c);
    res = scalar_mult(d, s->n);
    tmp = mult(s->n, res);
    sub_1 = sub(d, tmp);
    res = scalar_mult(delta_p, s->n);
    tmp = mult(s->n, res);
    sub_2 = sub(delta_p, tmp);
    abc->a = scalar_mult(sub_1,sub_1);
    abc->b = 2 * scalar_mult(sub_1, sub_2);
    abc->c = scalar_mult(sub_2, sub_2) - (s->r * s->r);
}

t_v             *intersect_ray_cylinder(t_v *d, t_v *p0, t_cylinder *s, double *t)
{
    t_abc       abc;
    t_v         *res;

//    write(1, ".", 1);
    find(&abc, d, p0, s);
    discriminant(t, abc);
    if (*t < 0)
        return (NULL);
    res = normal(add(mult(d, *t), p0));
    return (res);
}