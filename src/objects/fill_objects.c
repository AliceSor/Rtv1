/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:39:41 by asoroka           #+#    #+#             */
/*   Updated: 2017/08/12 18:34:24 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

static void		fill_plane(t_obj *p, t_v *new, t_color *color, double dist)
{
	t_v			*tmp;

	tmp = (t_v *)malloc(sizeof(t_v) + 1);
	p->color = color;
	normal(new, tmp);
	free(new);
	p->p = create_plane(tmp, dist);
}

static void		fill_sphere(t_obj *s, t_v *center, t_color *color, double rad)
{
	s->color = color;
	s->s = create_sphere(center, rad);
}

static void		fill_cylinder(t_obj *cl, t_v *n, t_color *color, t_v *c)
{
	t_v			*tmp;

	tmp = (t_v *)malloc(sizeof(t_v) + 1);
	cl->color = color;
	normal(n, tmp);
	free(n);
	cl->cl = create_cylinder(c, tmp);
}

static void		add_objects(t_rt *rt, t_obj **objects)
{
	objects[6] = create_obj(1);
	fill_plane(objects[6], NV(0, 1, 0), CC(0, 150, 150), 1500.0);
	objects[7] = create_obj(1);
	fill_plane(objects[7], NV(0, 0, 1), CC(100, 150, 150), 4801);
	add_obj(rt->obj, objects[7]);
	add_obj(rt->obj, objects[6]);
	add_obj(rt->obj, objects[5]);
	add_obj(rt->obj, objects[4]);
	add_obj(rt->obj, objects[3]);
	add_obj(rt->obj, objects[2]);
	add_obj(rt->obj, objects[1]);
	add_obj(rt->obj, objects[0]);
}

void			fill_objects(t_rt *rt)
{
	t_obj		**objects;

	objects = rt->objects;
	rt->obj = create_obj(-1);
	rt->obj->f->chosen = 1;
	objects[0] = create_obj(1);
	fill_plane(objects[0], NV(0, 1, 0), CC(0, 150, 150), 1501);
	objects[1] = create_obj(1);
	fill_plane(objects[1], NV(0, 0, 1), CC(100, 150, 150), 4800);
	objects[2] = create_obj(0);
	fill_sphere(objects[2], NV(-200, -100, 10), CC(80, 20, 200), 100);
	objects[3] = create_obj(0);
	fill_sphere(objects[3], NV(100, -300, -2000), CC(255, 255, 255), 20);
	objects[3]->f->for_light = 1;
	objects[4] = create_obj(2);
	fill_cylinder(objects[4], NV(1, 0, 1), CC(20, 80, 150), NV(-100, 200, 900));
	objects[5] = create_obj(3);
	objects[5]->color = CC(20, 150, 50);
	objects[5]->cn = create_cone(NV(400, -700, 2500), NV(0, 1, 0), 20);
	rt->lights = create_obj(4);
	rt->lights->l = create_light(NV(100, -300, -2000));
	rt->l_sphere = objects[3];
	add_objects(rt, objects);
}
