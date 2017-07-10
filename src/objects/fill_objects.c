//
// Created by Alisa Soroka on 5/31/17.🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙🐙
//

#include "../../rtv1.h"

void 			fill_objects(t_rt *rt)
{
	t_obj		*obj_p;
	t_obj		*obj_p1;
	t_obj		*obj_s;
	t_obj		*obj_s1;
	t_obj		*obj_cl;
	t_obj		*obj_cn;
//	t_obj		*obj_l0;

	rt->obj = create_obj(9);
//	rt->obj->color = create_color(0, 255, 255);
//	rt->obj->color = create_color(255, 255, 255);
//	rt->obj->p = create_plane(new_vector(0, 100, 1000), new_vector(0, 0, 1), 0x00FFFF, 100);
	rt->obj->f->chosen = 1;

	obj_p = create_obj(1);
	obj_p->color = create_color(0, 150, 150);
	t_v		*temp, *tmp;
	temp = new_vector(0, 1, 1);
	tmp = new_vector(0, 1, 1);
	normal(temp, tmp);
//	obj_p->color = create_color(0, 255, 255);
	obj_p->p = create_plane(new_vector(0, -100, 10000), tmp, 0x00AAAA, 1000);
	add_obj(rt->obj, obj_p);

	obj_p1 = create_obj(1);
	obj_p1->color = create_color(100, 150, 150);
//	obj_p1->color = create_color(0, 255, 255);
	obj_p1->p = create_plane(new_vector(0, -100, 10000), new_vector(0, 0, 1), 0x00AAAA, 1000);
	add_obj(rt->obj, obj_p1);

	obj_s = create_obj(0);
//	obj_s->color = create_color(50, 80, 100);
	obj_s->color = create_color(255, 0, 255);
	obj_s->s = create_sphere(new_vector(-200, -100, 10), 100, 0x3355AA);
	add_obj(rt->obj, obj_s);

	obj_s1 = create_obj(0);
//	obj_s->color = create_color(50, 80, 100);
	obj_s1->color = create_color(100, 100, 255);
	obj_s1->s = create_sphere(new_vector(-300, -300, 10), 50, 0x3355AA);
	add_obj(rt->obj, obj_s1);

	obj_cl = create_obj(2);
//	obj_cl->color = create_color(80, 70, 255);
	obj_cl->color = create_color(0, 0, 255);
	t_v		*temp1, *tmp1;
	temp1 = new_vector(1, 1, 0);
	tmp1 = new_vector(1, 0, 0);
	normal(temp1, tmp1);
	obj_cl->cl = create_cylinder(new_vector(-300, -200, 5), tmp1, 0x5577FF);
	add_obj(rt->obj, obj_cl);

	obj_cn = create_obj(3);
//	obj_cn->color = create_color(0, 100, 255);
	obj_cn->color = create_color(0, 255, 0);
	obj_cn->cn = create_cone(new_vector(200, -100, 5), new_vector(0, 1, 0), 0xAAFF, 20);
	add_obj(rt->obj, obj_cn);

	rt->lights = create_obj(4);
	rt->lights->l = create_light(new_vector(500, -800, -1000), 10);
}
