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
	if (obj->type_obj == 3)
		return (intersect_ray_cone(d, p0, obj->cn, t));
    else
        return (NULL);
}

//static int              choose_color(t_obj *obj)
//{
//    if (obj->type_obj == 0)
//        return (obj->s->color);
//    if (obj->type_obj == 1)
//        return (obj->p->color);
//    if (obj->type_obj == 2)
//        return (obj->cl->color);
//	if (obj->type_obj == 3)
//		return (obj->cn->color);
//    else
//        return (0);
//}

t_obj			*find_light_intersect(t_rt *rt, t_v *d, t_v *p0, int i)
{
	t_obj		*res;
	t_obj		*obj;
	double 		t;

	obj = rt->obj;
	res = NULL;
	t = HUGE;
	while (obj)
	{
		if (obj->f->l_change_pos == 0)
		{
			obj->l_is_intersct[i] = HUGE;
			obj->l_intersct[i] = choose_intersect(d, p0, obj, &(obj->l_is_intersct[i]));
		}
		if (obj->l_is_intersct[i] < rt->dist)
		{
			if (res)
			{
				if (t > obj->l_is_intersct[i])
				{
					res = obj;
					t = obj->l_is_intersct[i];
				}
			}
			else
				res = obj;
		}
		obj = obj->next;
	}
//	if (res == NULL)
//		write(1, "hi" , 2);
	return (res);
}


t_obj			*find_intersect(t_rt *rt, t_v *d, t_v *p0, int i)
{
	t_obj		*res;
	t_obj		*obj;
	double 		t;

	obj = rt->obj;
	res = NULL;
	t = HUGE;
	while (obj)
	{
		if (obj->f->change_pos == 0)
		{
			obj->is_intersects[i] = HUGE;
			obj->intersects[i] = choose_intersect(d, p0, obj, &(obj->is_intersects[i]));
		}
		if (obj->is_intersects[i] < HUGE) {
			if (res)
			{
				if (t > obj->is_intersects[i])
				{
					res = obj;
					t = obj->is_intersects[i];
				}
			}
//				res = (res->is_intersects[i] > obj->is_intersects[i]) ? obj : res;
			else
				res = obj;
		}
		obj = obj->next;
	}
	return (res);
}

//int				intersect(t_rt *rt, t_v *d, int i)
//{
//    t_obj		*obj;
//    int			color;
//    double		len;
////	double		len1;
//    double     	t;
//    t_v			*temp;
//
//    obj = rt->obj;
//    color = 0;
//    len = 2147483648;
//    while (obj)
//    {
//		//
////		if (obj->f->change_pos == 1)//Попробовать вручную обнулять массивы с сохраненными пересечениями🐙
////		{
////			if (obj->is_intersects[i] == 1)
////				temp = &(obj->intersects[i]);
////			else
////				temp = NULL;
////		}
////		else
//		//
//			temp = choose_intersect(d, rt->screen->eye, obj, &t);
//        if (temp)
//        {
////			len1 = module(sub(temp, rt->screen->eye));
//			//
////			if (obj->is_intersects[i] == 0 && obj->f->change_pos == 0)
////			{
////				obj->intersects[i] = *temp;
////				obj->is_intersects[i] = 1;
////			}
//			//
//			if (t < len)//точка пересечения ближе предыдущей
//			{
//				len = t;
//				color = (obj->f->chosen) ? 0x990033 : choose_color(obj);
//			}
//		}
//		//
////		else
////			obj->is_intersects[i] = 0;
//		//
//		obj = obj->next;
//	}
//	return (color);
//}