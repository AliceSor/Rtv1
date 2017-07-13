//
// Created by Alisa Soroka on 6/28/17.
//

#include "../rtv1.h"

t_obj			*intersect(t_rt *rt, t_v *d, double *t)
{
	t_obj		*res;
	t_obj		*obj;
	int 		is_intersect;
	double 		min_t;

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
	int 		is_intersect;
	double 		min_t;
	t_v			*res;

	obj = rt->obj;
	res = NULL;
	min_t = *t;
//	res = (t_v *)malloc(sizeof(t_v) + 1);
	while (obj)
	{
	//	*t = 2000000;
		is_intersect = identify_obj(d, p0, obj, t);
		if (is_intersect)
			if (*t < min_t - 1)
			{
				return (0);
			}
		obj = obj->next;
	}
//	*t = min_t;
////	if (*t < HUGE)
////	{
//		res = (t_v *) malloc(sizeof(t_v) + 1);
//		find_hit_point(*t, d, p0, res);
//	}
	return (1);
}

void 		ray_trace(t_rt *rt)
{
	t_v     *d;
	int     color;
	int		i;
	t_obj	*obj;
//	t_obj	*shadow_obj;
	t_v		*light_ray_hit;
	t_v		*light_ray;
	t_v		*hit_point;
	double 	t;
	double	diffuse;
	double 	specular;
	int 	is_shadow;
	t_v		temp_sub;

	i = 0;
	d = rt->screen->directions;
	/* move this code in rt-structure */
	hit_point = (t_v *)malloc(sizeof(t_v) + 1);
	light_ray = (t_v *)malloc(sizeof(t_v) + 1);
	while (i  < WIDTH * HEIGHT - 10)
	{
		obj = intersect(rt, &(d[i]), &t);
		if (obj)
		{
			diffuse = 0;
			specular = 0;
			find_hit_point(t, &(d[i]), EYE, hit_point);
			find_nrml_light_ray(hit_point, rt->lights->l->c, light_ray);
			is_shadow = intersect_light(rt, light_ray, rt->lights->l->c, &t);
			if (is_shadow)
			{
				diffuse = find_diffuse(obj, hit_point, light_ray);
				sub(hit_point, rt->lights->l->c, &temp_sub);
				t = module(&temp_sub);
				specular = find_specular(obj, hit_point, &(d[i]), light_ray);
			}
			color = calc_color(obj, diffuse, is_shadow, specular);
		}
		else
			color = 0;
		put_pixel(i, color, rt->mlx);
		i += rt->speed;
	}
}