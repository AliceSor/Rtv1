//
// Created by Alisa Soroka on 6/12/17.
//

#include "../../rtv1.h"

t_color			*create_color(double r, double g, double b)
{
	t_color		*n_c;
	n_c = (t_color *)malloc(sizeof(t_color) + 1);
	if (n_c)
	{
		n_c->r = 1 * r / 255;
		n_c->g = 1 * g / 255;
		n_c->b = 1 * b / 255;
		return (n_c);
	}
	return (NULL);
}