//
// Created by Alisa Soroka on 5/31/17.
//

#include "../../rtv1.h"

t_sphere			*create_sphere(t_v *c)
{
	t_sphere		*s;

	s = (t_sphere *)malloc(sizeof(t_sphere) + 1);
	if (s)
	{
		s->center = c;
		s->radius = 100;
		s->color = 0xFF00FF;
		return (s);
	}
	return (NULL);
	exit(1);
}