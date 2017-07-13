/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:51:03 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/17 17:06:32 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static void			fill_points(t_v *points)
{
	double			x;
	double			y;
	int 			i;
	t_v				*p;

	p = points;
	y = -(HEIGHT / 2);
	i = 0;
	while (y < HEIGHT / 2)
	{
		x = -(WIDTH / 2);
		while (x < WIDTH / 2)
		{
			p[i].x = x;
			p[i].y = y;
			p[i].z = -10;
			i++;
			x++;
		}
		y++;
	}
}

void				fill_directions(t_v *p, t_v *directions, t_screen *screen, t_rt *rt)
{
	int 			i_max;
	int 			i;
	t_v				*d;
	t_v				temp;
	t_v				temp_sub;
//	t_v				p1;

	i_max = HEIGHT * WIDTH;
	i = -1;
	d = directions;
	while (++i < i_max)
	{
		sub(&(p[i]), screen->r_eye, &temp_sub);
		normal(&temp_sub, &temp);
		v_copy(&temp, d);
		d++;
	}
}

void				fill_r_points(t_v *r_p, t_v *p, t_rt *rt)
{
	int 			i;

	i = 0;
	while (i  < WIDTH * HEIGHT - 10)
	{
		if (rt->costul > 0)
		{
//			(rt->costul == 1) ? rotate_x_point(&(p[i]), rt, &(r_p[i])) : 0;
//			(rt->costul == 2) ? rotate_y_point(&(p[i]), rt, &(r_p[i])) : 0;
		if (rt->costul == 3)
			rotate_z_point(&(p[i]), rt, &(r_p[i]));
		else
			absolute_rotate(&(p[i]), rt, &(r_p[i]));
		}
		else
		{
			r_p[i].x = p[i].x;
			r_p[i].y = p[i].y;
			r_p[i].z = p[i].z;
		}
		i += 1;
	}
	if (rt->costul > 0)
	{
		if (rt->costul == 3)
			rotate_x_point(rt->screen->eye, rt, rt->screen->r_eye);
		else
			absolute_rotate(rt->screen->eye, rt, rt->screen->r_eye);

//		(rt->costul == 1) ? rotate_x_point(rt->screen->eye, rt, rt->screen->r_eye) : 0;
//		(rt->costul == 2) ? rotate_x_point(rt->screen->eye, rt, rt->screen->r_eye) : 0;
//		(rt->costul == 3) ?  : 0;
	}
}

t_screen			*init_pos_screen(t_rt *rt)
{
	t_screen		*s;
	s = (t_screen *)malloc(sizeof(t_screen) + 1);
	s->alpha = 0;
	s->beta = 0;
	s->gamma = 0;
	s->eye = (t_v *)malloc(sizeof(t_v) + 1);
	s->r_eye = (t_v *)malloc(sizeof(t_v) + 1);
	s->center = (t_v *)malloc(sizeof(t_v) + 1);
	s->eye->x = 0.1;
	s->eye->y = 0.1;
	s->eye->z = -1000.1;
	s->r_eye->x = 0;
	s->r_eye->y = 0;
	s->r_eye->z = -1000;
	s->center->x = 0.0f;
	s->center->y = 0.0f;
	s->center->z = 0.0f;
	s->points = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
	s->r_points = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
	s->directions = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
	if (!s->points)
		exit(1);
	rt->costul = 0;
	fill_points(s->points);
	fill_r_points(s->r_points, s->points, rt);
	fill_directions(s->r_points, s->directions, s, rt);
	rt->costul = 1;
	return (s);
}
