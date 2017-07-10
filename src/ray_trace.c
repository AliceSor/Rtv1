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
//			res = (*t < min_t) ? obj : res; //в целях оптимицации можно заменить на if
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

int 		check_distanse(t_v *hit_p, t_v *light_hit, t_v *light_p)
{
	double 	dist_light;
	double 	dist_hit;
	t_v		temp_sub;

	sub(light_p, hit_p, &temp_sub);
	dist_light = module(&temp_sub);
	sub(light_hit, hit_p, &temp_sub);
	dist_hit = module(&temp_sub);
	if (dist_light < dist_hit)
		return (0);
	else
		return (1);
}

//
//int		shadow(t_rtv *mst, float dist)
//{
//	t_vec temp;
//	t_vec point;
//	t_vec light_dir;
//	t_vec dir_n;
//	float len;
//
//	temp = ft_mult_vec(dist, &mst->ray.dir_n);
//	point = ft_vector_add(&mst->ray.start, &temp);
//	light_dir = ft_vector_sub(&mst->light.pos, &point);
//	dir_n = normalize_vector(mst, light_dir.x, light_dir.y, light_dir.z);
//	len = ft_vector_mod(&light_dir);
//	if (cylinder(mst, &dir_n, &point) == 1 && LEN < len && (F == 2 || F == 6))
//		return (0);
//	if (sphere(mst, &dir_n, &point) == 1 && LEN < len && (F == 1 || F == 6))
//		return (0);
//	if (cone(mst, &dir_n, &point) == 1 && (LEN < len) && (F == 3 || F == 6))
//		return (0);
//	if (plane(mst, &dir_n, &point) == 1 && (LEN < len) && (F == 4 || F == 6))
//		return (0);
//	if (plane2(mst, &dir_n, &point) == 1 && (LEN < len) && (F == 4 || F == 6))
//		return (0);
//	return (1);

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
//	t = HUGE;
	/* move this code in rt-structure */
	hit_point = (t_v *)malloc(sizeof(t_v) + 1);
	light_ray = (t_v *)malloc(sizeof(t_v) + 1);
//	is_shadow = 1;
	while (i  < WIDTH * HEIGHT - 10)
	{
//		specular = 1;
		obj = intersect(rt, &(d[i]), &t);
		if (obj)
		{
			find_hit_point(t, &(d[i]), EYE, hit_point);
			find_nrml_light_ray(hit_point, rt->lights->l->c, light_ray);
			diffuse = find_diffuse(obj, hit_point, light_ray);
			sub(hit_point, rt->lights->l->c, &temp_sub);
			t = module(&temp_sub);
			is_shadow = intersect_light(rt, light_ray, rt->lights->l->c, &t);
//			if (is_shadow)
				specular = find_specular(obj, hit_point, &(d[i]), light_ray);
			color = calc_color(obj, diffuse, is_shadow, specular);
		}
		else
			color = 0;
		put_pixel(i, color, rt->mlx);
		i += rt->speed;
	}
}
////- Переделать intersect && intersect_light; - DONE
////- Переделать пресечения с фигурами, чтобы они не высчитывали точку пересечения - DONE
//Ну крч почти все переписать заново 😅