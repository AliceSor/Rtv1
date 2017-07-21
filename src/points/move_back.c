/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:44:04 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:44:07 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			move_x_point_b(t_v *p, t_rt *rt)
{
	p->x -= 5 * rt->speed_move;
}

void			move_y_point_b(t_v *p, t_rt *rt)
{
	p->y -= 5 * rt->speed_move;
}

void			move_z_point_b(t_v *p, t_rt *rt)
{
	p->z -= 5 * rt->speed_move;
}
