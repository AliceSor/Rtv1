//
// Created by Alisa Soroka on 5/31/17.
//

#include "../../rtv1.h"

t_sphere			*create_sphere(t_v *c, double r, int color)
{
	t_sphere		*s;

	s = (t_sphere *)malloc(sizeof(t_sphere) + 1);
	if (s)
	{
		s->center = c;
		s->radius = r;
		s->color = color;
		return (s);
	}
	return (NULL);
	exit(1);
}