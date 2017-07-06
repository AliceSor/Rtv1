//
// Created by Alisa Soroka on 6/3/17.
//

#include "../../rtv1.h"

t_cone		*create_cone(t_v *c, t_v *n, int color, double angle)
{
	t_cone	*s;

	s = (t_cone *)malloc(sizeof(t_cone) + 1);
	if (s)
	{
		angle *= RAD;
		s->c = c;
		s->n = n;
		s->color = color;
		s->cos_a = cos(angle) * cos(angle);
		s->sin_a = sin(angle) * sin(angle);
		s->cos_a2 = 2 * (cos(angle) * cos(angle));
		s->sin_a2 = 2 * (sin(angle) * sin(angle));
		return (s);
	}
	exit(1);
}