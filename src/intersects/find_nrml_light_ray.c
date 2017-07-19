/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nrml_light_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:16:08 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 17:16:47 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void			find_nrml_light_ray(t_v *hit_p, t_v *light_p, t_v *res)
{
	t_v			tmp_sub;
	t_v			tmp_mlt;

	sub(light_p, hit_p, &tmp_sub);
	mult(&tmp_sub, -1, &tmp_mlt);
	normal(&tmp_mlt, res);
}
