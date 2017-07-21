/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:30:14 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:31:11 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			move_x_point(t_v *p, t_rt *rt)
{
	p->x += 5 * rt->speed_move;
}

void			move_y_point(t_v *p, t_rt *rt)
{
	p->y += 5 * rt->speed_move;
}

void			move_z_point(t_v *p, t_rt *rt)
{
	p->z += 5 * rt->speed_move;
}
