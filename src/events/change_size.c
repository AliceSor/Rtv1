/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:51:24 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:51:28 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void		change_size(int keycode, t_rt *rt)
{
	if (keycode == 24)
		(rt->chosen->type_obj == 0) ? (rt->chosen->s->radius += 10.0)
									: (rt->chosen->cl->r += 10.0);
	if (keycode == 27)
		(rt->chosen->type_obj == 0) ? (rt->chosen->s->radius -= 10.0)
									: (rt->chosen->cl->r -= 10.0);
}
