/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:38:55 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:38:57 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

t_sphere			*create_sphere(t_v *c, double r)
{
	t_sphere		*s;

	s = (t_sphere *)malloc(sizeof(t_sphere) + 1);
	if (s)
	{
		s->center = c;
		s->radius = r;
		return (s);
	}
	exit(1);
}
