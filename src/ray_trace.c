#include "../rtv1.h"

t_obj			*intersect(t_rt *rt, t_v *d, double *t)
{
	t_obj		*res;
	t_obj		*obj;
	int			is_intersect;
	double		min_t;

	obj = rt->obj;
	res = NULL;
	min_t = HUGE;
	*t = HUGE;
	while (obj)
	{
		*t = HUGE;
		is_intersect = identify_obj(d, EYE, obj, t);
		if (is_intersect)
			if (*t < min_t)
			{
				res = obj;
				min_t = *t;
			}
		obj = obj->next;
	}
	*t = min_t;
	return (res);
}

int				intersect_light(t_rt *rt, t_v *d, t_v *p0, double *t)
{
	t_obj		*obj;
	int			is_intersect;
	double		min_t;

	obj = rt->obj;
	min_t = *t;
	while (obj)
	{
		if (obj->f->for_light == 0)
		{
			is_intersect = identify_obj(d, p0, obj, t);
			if (is_intersect)
				if (*t < min_t - 1)
					return (0);
		}
		obj = obj->next;
	}
	return (1);
}

static int	find_light(t_rt *rt, t_obj *obj, t_v *d, double *t)
{
	double	diffuse;
	double	specular;
	int		is_shadow;

	diffuse = 0;
	specular = 0;
	find_hit_point(*t, d, EYE, rt->hit_point);
	find_nrml_light_ray(rt->hit_point, rt->lights->l->c, rt->light_ray);
	sub(rt->hit_point, rt->lights->l->c, rt->temp_sub);
	*t = module(rt->temp_sub);
	is_shadow = intersect_light(rt, rt->light_ray, rt->lights->l->c, t);
	if (is_shadow)
	{
		diffuse = find_diffuse(obj, rt->hit_point, rt->light_ray);
		specular = find_specular(obj, rt->hit_point, d, rt->light_ray);
	}
	return (calc_color(obj, diffuse, is_shadow, specular));
}

void 		ray_trace(t_rt *rt)
{
	t_v		*d;
	int		color;
	int		i;
	t_obj	*obj;
	double	t;

	i = 0;
	d = rt->screen->directions;
	while (i  < WIDTH * HEIGHT - 10)
	{
		obj = intersect(rt, &(d[i]), &t);
		if (obj)
		{
			if (rt->is_light)
				color  = find_light(rt, obj, &(d[i]), &t);
			else
				color = integrate_color(CR, CG, CB);
		}
		else
			color = 0;
		put_pixel(i, color, rt->mlx);
		i += rt->speed;
	}
}