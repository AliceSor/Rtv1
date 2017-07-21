/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:39:41 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:40:14 by asoroka          ###   ########.fr       */
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

	objects = (t_obj **)malloc(sizeof(t_obj *) * 10 + 1);
	objects[0] = create_obj(1);
	rt->obj = create_obj(-1);
	rt->obj->f->chosen = 1;
	objects[0] = create_obj(1);
	fill_plane(objects[0], NV(0, 1, 0), CC(0, 150, 150), 1501);
	objects[1] = create_obj(1);
	fill_plane(objects[1], NV(0, 0, 1), CC(100, 150, 150), 4800);
	objects[2] = create_obj(0);
	fill_sphere(objects[2], NV(-200, -100, 10), CC(80, 20, 200), 100);
	objects[3] = create_obj(0);
	fill_sphere(objects[3], NV(0, -80, 0), CC(255, 255, 255), 20);
	objects[3]->f->for_light = 1;
	objects[4] = create_obj(2);
	fill_cylinder(objects[4], NV(1, 0, 1), CC(20, 80, 150), NV(-100, 200, 900));
	objects[5] = create_obj(3);
	objects[5]->color = CC(20, 150, 50);
	objects[5]->cn = create_cone(NV(400, -300, 1400), NV(0, 1, 0), 20);
	rt->lights = create_obj(4);
	rt->lights->l = create_light(NV(0, -80, 0));
	rt->l_sphere = objects[3];
	add_objects(rt, objects);
}


//static void		fill_plane(t_obj *obj_p, t_v *new, t_color *color, double dist)
//{
//    t_v			*tmp;
//
//    tmp = (t_v *)malloc(sizeof(t_v) + 1);
//    obj_p->color = color;
//    normal(new, tmp);
//    free(new);
//    obj_p->p = create_plane(tmp, dist);
//}
//
//void 			fill_objects(t_rt *rt)
//{
//    t_obj		*obj_p;
//    t_obj		*obj_p1;
//    t_obj		*obj_s;
//    t_obj		*obj_s1;
//    t_obj		*obj_cl;
//    t_obj		*obj_cn;
//
//    rt->obj = create_obj(-1);
//    rt->obj->f->chosen = 1;
//    obj_p = create_obj(1);
//    fill_plane(obj_p, new_vector(0, 1, 0), create_color(0, 150, 150), 1501);
//    obj_p1 = create_obj(1);
//    fill_plane(obj_p1, new_vector(0, 0, 1), create_color(100, 150, 150), 4800);
//    obj_s = create_obj(0);
//    obj_s->color = create_color(80, 20, 200);
//    obj_s->s = create_sphere(new_vector(-200, -100, 10), 100);
//    obj_s1 = create_obj(0);
//    obj_s1->color = create_color(255, 255, 255);
//    obj_s1->s = create_sphere(new_vector(0, -80, 0), 20);
//    obj_s1->f->for_light = 1;
//    obj_cl = create_obj(2);
//    obj_cl->color = create_color(20, 80, 150);
//    t_v		*temp1, *tmp1;
//    temp1 = new_vector(1, 0, 1);
//    tmp1 = new_vector(1, 0, 0);//use like malloc
//    normal(temp1, tmp1);
//    obj_cl->cl = create_cylinder(new_vector(-100, 200, 900), tmp1);
//    obj_cn = create_obj(3);
//    obj_cn->color = create_color(20, 150, 50);
//    obj_cn->cn = create_cone(new_vector(400, -300, 1400), new_vector(0, 1, 0), 20);
//    rt->lights = create_obj(4);
//    rt->lights->l = create_light(new_vector(0, -80, 0));
//    rt->l_sphere = obj_s1;
//    add_obj(rt->obj, obj_s);
//    add_obj(rt->obj, obj_s1);
//    add_obj(rt->obj, obj_cl);
//    add_obj(rt->obj, obj_cn);
//    add_obj(rt->obj, obj_p1);
//    add_obj(rt->obj, obj_p);
//}
