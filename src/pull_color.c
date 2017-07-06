//
// Created by Alisa Soroka on 6/15/17.
//

#include "../rtv1.h"

//static double 			obj_dist(t_obj *o0, t_obj *o1)
//{
//	t_v			*p1;
//	t_v 		*p2;
//
//	if (o0 && 01)
//	{
//		if (o0->type_obj == 0)
//			p1 = o0->s->
//	}
//	return (HUGE);
//}

int 			pull_color(t_obj *o0, t_obj *o1, t_light *l, int i)
{
	int 		res;
	double 		r;
	double 		g;
	double 		b;
	double 		dist;
	double		dist1, dist2;

	res = 0;
	if (o0)
	{
//		write(1, ".", 1);
//		dist = module(sub(o0->intersects[i], l->c));
//		dist1 = (o1) ? module(sub(o0->intersects[i], o1->l_intersct[i])) : HUGE;
//		dist2 = (o1) ? module(sub(l->c, o1->l_intersct[i])) : HUGE;
		if (o0->f->chosen == 1)
		{
			r = 230;
			g = 0;
			b = 20;
		}
		else
		{
			r = o0->color->r;
			g = o0->color->g;
			b = o0->color->b;
		}
//		if (!o1 || (dist < dist1))
		if (!o1)
		{
			write(1, ".", 1);
			r *= l->brightness;
			g *= l->brightness;
			b *= l->brightness;
		}
		else
		{
			r /= 2;
			b /= 2;
			g /= 2;
		}
		res = ((int)r << 16) + ((int)g << 8) + (int)b;
	}
	return (res);
}