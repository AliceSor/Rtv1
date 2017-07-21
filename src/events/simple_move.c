/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:10:14 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 19:10:17 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	simple_move(int keycode, t_rt *rt)
{
	if (keycode == 86)
		for_each_point(rt, move_x_point_b);
	else if (keycode == 88)
		for_each_point(rt, move_x_point);
	else if (keycode == 89)
		for_each_point(rt, move_y_point_b);
	else if (keycode == 83)
		for_each_point(rt, move_y_point);
	else if (keycode == 91)
		for_each_point(rt, move_z_point);
	else if (keycode == 84)
		for_each_point(rt, move_z_point_b);
}
