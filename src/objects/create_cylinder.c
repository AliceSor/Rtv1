/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:39:27 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:39:30 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

t_cylinder		*create_cylinder(t_v *c, t_v *n)
{
	t_cylinder	*s;

	s = (t_cylinder *)malloc(sizeof(t_cylinder) + 1);
	if (s)
	{
		s->c = c;
		s->n = n;
		s->r = 100;
		return (s);
	}
	exit(1);
}
