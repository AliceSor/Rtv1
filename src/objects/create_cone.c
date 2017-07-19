/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:38:45 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:38:48 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

t_cone		*create_cone(t_v *c, t_v *n, double angle)
{
	t_cone	*s;

	s = (t_cone *)malloc(sizeof(t_cone) + 1);
	if (s)
	{
		angle *= RAD;
		s->c = c;
		s->n = n;
		s->sub_1 = (t_v *)malloc(sizeof(t_v) + 1);
		s->sub_2 = (t_v *)malloc(sizeof(t_v) + 1);
		s->cos_a = cos(angle) * cos(angle);
		s->sin_a = sin(angle) * sin(angle);
		s->cos_a2 = 2 * (cos(angle) * cos(angle));
		s->sin_a2 = 2 * (sin(angle) * sin(angle));
		return (s);
	}
	exit(1);
}
