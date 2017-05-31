//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

static t_v             *choose_intersect(t_v *d,t_v *p0, t_obj *obj, double *t)
{
    if (obj->type_obj == 0)
        return (intersect_ray_sphere(d, p0, obj->s, t));
    if (obj->type_obj == 1)
        return (intersect_ray_plane(d, p0, obj->p, t));
    if (obj->type_obj == 2)
        return (intersect_ray_cylinder(d, p0, obj->cl, t));
    else
        return (NULL);
}

static int              choose_color(t_obj *obj)
{
    if (obj->type_obj == 0)
        return (obj->s->color);
    if (obj->type_obj == 1)
        return (obj->p->color);
    if (obj->type_obj == 2)
        return (obj->cl->color);
    else
        return (0);
}

int				intersect(t_rt *rt, t_v *d)
{
    t_obj		*obj;
    int			color;
    double		len;
	double		len1;
    double     t;
    t_v			*temp;
    int         f;

	f = 0;
    obj = rt->obj;
    color = 0;
    len = 2147483648;
    while (obj && f <6)
    {
        f++;
        if ((temp = choose_intersect(d, rt->screen->eye, obj, &t)))
        {
			len1 = module(sub(temp, rt->screen->eye));
            if (t < len)//точка пересечения ближе предыдущей
            {
				len = len1;
                color = choose_color(obj);
            }
        }
        obj = obj->next;
    }
    return (color);
}