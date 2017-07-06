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
			/* printf("(%f, %f, %f)", p->x, p->y, p->z); */
			x++;
		}
		y++;
		/* printf("\n\n"); */
	}
}

void				fill_directions(t_v *p, t_v *directions, t_screen *screen, t_rt *rt)
{
	int 			i_max;
	int 			i;
	t_v				*d;
	t_v				temp;
	t_v				temp_sub;
//	t_v				*p1;

	i_max = HEIGHT * WIDTH;
	i = -1;
	d = directions;
//	p1 = (t_v *)malloc(sizeof(t_v) + 1);
	while (++i < i_max)
	{
//		v_copy(p1, &(p[i]));
//		if (rt->costul == 1)
//		{
//			rotate_x_point(p1, rt);
//			rotate_x_point(p1, rt);
//			rotate_x_point(p1, rt);
//		}
		sub(&(p[i]), screen->eye, &temp_sub);
		normal(&temp_sub, &temp);
		v_copy(&temp, d);
		d++;
	}
}

t_screen			*init_pos_screen(t_rt *rt)
{
	t_screen		*s;
	s = (t_screen *)malloc(sizeof(t_screen) + 1);
	s->alpha = 30;
	s->beta = 30;
	s->gamma = 0;
	s->eye = (t_v *)malloc(sizeof(t_v) + 1);
	s->center = (t_v *)malloc(sizeof(t_v) + 1);
	s->eye->x = 0.0f;
	s->eye->y = 0.0f;
	s->eye->z = -1000;
	s->center->x = 0.0f;
	s->center->y = 0.0f;
	s->center->z = 0.0f;
	s->points = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
	s->directions = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
	if (!s->points)
		exit(1);
	fill_points(s->points);
	fill_directions(s->points, s->directions, s, rt);
	rt->costul = 1;
	return (s);
}
