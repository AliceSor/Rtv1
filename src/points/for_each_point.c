/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_point_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:33:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:33:15 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	rotate_z_point(t_v *p, t_rt *rt, t_v *res)
{
	res->x = p->x * cos(G * RAD) - p->y * sin(G * RAD);
	res->y = p->x * sin(G * RAD) + p->y * cos(G * RAD);
}

void	absolute_rotate(t_v *p, t_rt *rt, t_v *res)
{
	res->x = p->x * cos(G * RAD) * cos(B * RAD) + p->y * (cos(G * RAD)
		* sin(B * RAD) * sin(A * RAD) - sin(G * RAD) * cos(A * RAD))
	+ p->z * (cos(G * RAD) * sin(B * RAD) * cos(A * RAD) - sin(G * RAD)
		* sin(A * RAD));
	res->y = p->x * sin(G * RAD) * cos(B * RAD) + p->y * (sin(G * RAD)
	* sin(A * RAD) * sin(B * RAD) + cos(G * RAD) * cos(A * RAD)) + p->z *
	(sin(G * RAD) * sin(B * RAD) * cos(A * RAD) - cos(G * RAD) * sin(A * RAD));
	res->z = p->x * (-p->z * sin(G * RAD)) + p->y * cos(B * RAD) * sin(A * RAD)
	+ p->z * cos(B * RAD) * cos(A * RAD);
}

void	for_each_point(t_rt *rt, void (*f)(t_v *, t_rt *))
{
	t_v	*p;
	int	i;
	int	i_max;

	p = rt->screen->points;
	i = 0;
	i_max = HEIGHT * WIDTH;
	if (p && rt->screen->eye)
	{
		while (i < i_max)
		{
			(*f)(&(p[i]), rt);
			i++;
		}
		(*f)(rt->screen->eye, rt);
	}
}
