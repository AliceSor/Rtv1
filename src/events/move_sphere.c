/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:52:37 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:52:41 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			move_sphere(int keycode, t_rt *rt)
{
	if (keycode == 123)
		rt->chosen->s->center->x -= 100;
	else if (keycode == 124)
		rt->chosen->s->center->x += 100;
	else if (keycode == 126)
		rt->chosen->s->center->y -= 100;
	else if (keycode == 125)
		rt->chosen->s->center->y += 100;
	else if (keycode == 78)
		rt->chosen->s->center->z += 100;
	else if (keycode == 69)
		rt->chosen->s->center->z -= 100;
}
