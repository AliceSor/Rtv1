/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:53:07 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:53:08 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			move_y(int keycode, t_rt *rt)
{
	if (keycode == 1)
	{
		rt->lights->l->c->y += 5 * rt->speed_move;
		rt->l_sphere->s->center->y += 5 * rt->speed_move;
	}
	else if (keycode == 13)
	{
		rt->lights->l->c->y -= 5 * rt->speed_move;
		rt->l_sphere->s->center->y -= 5 * rt->speed_move;
	}
	else if (keycode == 16)
	{
		B += 2 * rt->speed_rotate;
		rt->costul = 2;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, DIRS, rt->screen, rt);
	}
	else if (keycode == 32)
	{
		B -= 2 * rt->speed_rotate;
		rt->costul = 2;
		fill_r_points(rt->screen->r_points, rt->screen->points, rt);
		fill_directions(rt->screen->r_points, DIRS, rt->screen, rt);
	}
}
