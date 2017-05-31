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

static void		fill_points(t_v *points)
{
	double		x;
	double		y;
	int 		i;
	t_v			*p;

	p = points;
	y = 0;
	i = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			p[i].x = x;
			p[i].y = y;
			p[i].z = 0;
			i++;
			/* printf("(%f, %f, %f)", p->x, p->y, p->z); */
			x++;
		}
		y++;
		/* printf("\n\n"); */
	}
}

static void		fill_directions(t_v *p, t_v *directions, t_screen *screen)
{
	int 			i_max;
	int 			i;
	t_v				*d;
    t_v           *temp;

	i_max = HEIGHT * WIDTH;
	i = -1;
	d = directions;
	while (++i < i_max)
	{
		temp = normal(sub(&(p[i]), screen->eye));
        v_copy(temp, d);
		d++;
	}
}

t_screen			*init_pos_screen(void)
{
	t_screen		*s;
	s = (t_screen *)malloc(sizeof(t_screen) + 1);
	s->eye = (t_v *)malloc(sizeof(t_v) + 1);
	s->center = (t_v *)malloc(sizeof(t_v) + 1);
	s->eye->x = WIDTH / 2;
	s->eye->y = HEIGHT / 2;
	s->eye->z = -400;
	s->center->x = WIDTH / 2;
	s->center->y = HEIGHT / 2;
	s->center->z = 0.1;
	s->points = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
    s->directions = (t_v *)malloc((WIDTH * HEIGHT + 1) * sizeof(t_v));
	if (!s->points)
		exit(1);
	fill_points(s->points);
	fill_directions(s->points, s->directions, s);
	return (s);
}
