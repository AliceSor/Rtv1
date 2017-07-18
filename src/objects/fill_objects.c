//
// Created by Alisa Soroka on 5/31/17.🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
//

#include "../../rtv1.h"

static void		fill_plane(t_obj *obj_p, t_v *new, t_color *color, double dist)
{
	t_v			*tmp;

	tmp = (t_v *)malloc(sizeof(t_v) + 1);
	obj_p->color = color;
	normal(new, tmp);
	free(new);
	obj_p->p = create_plane(NULL, tmp, 0, dist);
}

void 			fill_objects(t_rt *rt)
{
	t_obj		*obj_p;
	t_obj		*obj_p1;
	t_obj		*obj_s;
	t_obj		*obj_s1;
	t_obj		*obj_cl;
	t_obj		*obj_cn;

	rt->obj = create_obj(-1);
	rt->obj->f->chosen = 1;
	obj_p = create_obj(1);
	fill_plane(obj_p, new_vector(0, 1, 0), create_color(0, 150, 150), 1501);
	obj_p1 = create_obj(1);
	fill_plane(obj_p1, new_vector(0, 0, 1), create_color(100, 150, 150), 4800);
	obj_s = create_obj(0);
	obj_s->color = create_color(80, 20, 200);
	obj_s->s = create_sphere(new_vector(-200, -100, 10), 10000, 0x3355AA);
	obj_s1 = create_obj(0);
	obj_s1->color = create_color(255, 255, 255);
	obj_s1->s = create_sphere(new_vector(0, -80, 0), 20, 0x3355AA);
	obj_s1->f->for_light = 1;
	obj_cl = create_obj(2);
	obj_cl->color = create_color(20, 80, 150);
	t_v		*temp1, *tmp1;
	temp1 = new_vector(1, 0, 1);
	tmp1 = new_vector(1, 0, 0);//use like malloc
	normal(temp1, tmp1);
	obj_cl->cl = create_cylinder(new_vector(-100, 200, 900), tmp1, 0x5577FF);
	obj_cn = create_obj(3);
	obj_cn->color = create_color(20, 150, 50);
	obj_cn->cn = create_cone(new_vector(400, -300, 1400), new_vector(0, 1, 0), 0xAAFF, 20);
	rt->lights = create_obj(4);
	rt->lights->l = create_light(new_vector(0, -80, 0), 10);
    rt->l_sphere = obj_s1;
	add_obj(rt->obj, obj_s);
	add_obj(rt->obj, obj_s1);
	add_obj(rt->obj, obj_cl);
	add_obj(rt->obj, obj_cn);
	add_obj(rt->obj, obj_p1);
	add_obj(rt->obj, obj_p);
}
