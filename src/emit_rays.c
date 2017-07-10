/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:57:40 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/19 18:57:48 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

//static int 	temporary(t_obj *obj, int i, t_v *ray_to_light)
//{
//	int 	res;
//	double 	r;
//	double 	g;
//	double 	b;
//	double 	temp_cos;
//	t_v		*nrml;
//	t_v		*tmp;
//
//	nrml = (t_v *)malloc(sizeof(t_v) +1);
//	tmp = (t_v *)malloc(sizeof(t_v) +1);
//	res = 0;
//	if (obj)
//	{
//		if (obj->type_obj == 0 || obj->type_obj == 1)
//		{
//			if (obj->type_obj == 0)
//			{
//				sub(obj->s->center, obj->intersects[i], tmp);
//				normal(tmp, nrml);
//				temp_cos = scalar_mult(nrml, ray_to_light);
//			}
//			else
//			{
//				temp_cos = scalar_mult(obj->p->n, ray_to_light);
//			}
//			r = (obj->color->r * temp_cos) + obj->color->r * 0.2;
//			g = (obj->color->g * temp_cos) + obj->color->g * 0.2;
//			b = (obj->color->b * temp_cos) + obj->color->b * 0.2;
//			res = integrate_color(r, g, b);
//		}
//		else
//		{
//			if (obj->f->chosen == 1)
//				res = integrate_color(100, 0, 20);
//			else
//			{
//				r = obj->color->r / 2.5;
//				g = obj->color->g / 2.5;
//				b = obj->color->b / 2.5;
//				res = integrate_color(r, g, b);
//			}
//		}
//	}
//	return (res);
//}
//
//void        emit_rays(t_rt *rt)
//{
//
////    t_v     *p;
//    t_v     *d;
//    int     color;
//	t_obj	*temp0;
//	t_obj	*temp1;
//	t_v		t_sub;
//	t_v		*tmp;
//	t_v		*ray_to_light;
//	int		i;
//
//	i = 0;
////    p = rt->screen->points;
//	tmp = (t_v *)malloc(sizeof(t_v) + 1);
//	ray_to_light = (t_v *)malloc(sizeof(t_v) + 1);
//    d = rt->screen->directions;
//    while (i  < WIDTH * HEIGHT - 10)
//    {
//		temp0 = find_intersect(rt, &(d[i]), rt->screen->eye, i);
//		if (temp0)
//		{
////			sub(temp0->intersects[i], rt->lights->l->c, &t_sub);
////			rt->dist = module(&t_sub);
////			sub(rt->lights->l->c, temp0->intersects[i], &t_sub);
////			temp1 = find_light_intersect(rt, &t_sub , rt->lights->l->c, i);
////			color = pull_color(temp0, temp1, rt->lights->l, i);
////			sub(rt->lights->l->c, temp0->intersects[i], tmp);
//			sub(temp0->intersects[i], rt->lights->l->c, tmp);
//			normal(tmp, ray_to_light);
//			color = temporary(temp0, i, ray_to_light);
//		}
//		else
//			color = 0;
//		put_pixel(i, color, rt->mlx);
//		i += rt->speed;
//    }
//}
