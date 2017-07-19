/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:39:14 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:39:18 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

t_plane			*create_plane(t_v *n, double dist)
{
	t_plane		*s;

	s = (t_plane *)malloc(sizeof(t_sphere) + 1);
	if (s)
	{
		s->n = n;
		s->dist = dist;
		return (s);
	}
	exit(1);
}
