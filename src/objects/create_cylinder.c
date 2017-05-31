//
// Created by Alisa Soroka on 5/31/17.
//

#include "../../rtv1.h"

t_cylinder		*create_cylinder(t_v *c, t_v *n, int color)
{
	t_cylinder	*s;

	s = (t_cylinder *)malloc(sizeof(t_cylinder) + 1);
	if (s)
	{
		s->c = c;
		s->n = n;
		s->color = color;
		s->r = 10;
		return (s);
	}
	exit(1);
}