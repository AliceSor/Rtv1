//
// Created by Alisa Soroka on 6/12/17.
//

#include "../../rtv1.h"

t_light			*create_light(t_v *c, double brightness)
{
	t_light		*s;

	s = (t_light *)malloc(sizeof(t_light) + 1);
	if (s)
	{
		s->c = c;
		s->brightness = brightness;
		return (s);
	}
	exit(1);
}