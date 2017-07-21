/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:53:14 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:53:16 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			move_z(int keycode, t_rt *rt)
{
	if (keycode == 116)
	{
		rt->lights->l->c->z += 5 * rt->speed_move;
		rt->l_sphere->s->center->z += 5 * rt->speed_move;
	}
	else if (keycode == 121)
	{
		rt->lights->l->c->z -= 5 * rt->speed_move;
		rt->l_sphere->s->center->z -= 5 * rt->speed_move;
	}
	else if (keycode == 6)
	{
		G += 2 * rt->speed_rotate;
		rt->costul = 3;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, DIRS, rt->screen, rt);
	}
	else if (keycode == 261)
	{
		G -= 2 * rt->speed_rotate;
		rt->costul = 3;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, DIRS, rt->screen, rt);
	}
}
