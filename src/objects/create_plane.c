//
// Created by Alisa Soroka on 5/31/17.
//

#include "../../rtv1.h"

t_plane			*create_plane(t_v *c, t_v *n, int color, double dist)
{
	t_plane		*s;

	s = (t_plane *)malloc(sizeof(t_sphere) + 1);
	if (s)
	{
		s->c = c;
		s->n = n;
		s->color = color;
		s->dist = dist;
		return (s);
	}
	exit(1);
}