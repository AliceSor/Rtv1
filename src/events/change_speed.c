/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_speed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:51:36 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:51:40 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void				change_speed(int keycode, t_rt *rt)
{
	if (keycode == 92)
		rt->speed_move += 10;
	else if (keycode == 85)
		rt->speed_move -= 10;
	else if (keycode == 82)
		rt->speed_rotate -= 5;
	else if (keycode == 65)
		rt->speed_rotate += 5;
	else if (keycode == 76)
		(rt->speed)++;
	else if (keycode == 67 && rt->speed > 1)
		(rt->speed)--;
}
