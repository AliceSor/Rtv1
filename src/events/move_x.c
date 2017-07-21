/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:52:58 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:52:59 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			move_x(int keycode, t_rt *rt)
{
	if (keycode == 0)
	{
		rt->lights->l->c->x -= 5 * rt->speed_move;
		rt->l_sphere->s->center->x -= 5 * rt->speed_move;
	}
	else if (keycode == 2)
	{
		rt->lights->l->c->x += 5 * rt->speed_move;
		rt->l_sphere->s->center->x += 5 * rt->speed_move;
	}
	else if (keycode == 7)
	{
		A += 2 * rt->speed_rotate;
		rt->costul = 1;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, DIRS, rt->screen, rt);
	}
	else if (keycode == 8)
	{
		A -= 2 * rt->speed_rotate;
		rt->costul = 1;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, DIRS, rt->screen, rt);
	}
}
