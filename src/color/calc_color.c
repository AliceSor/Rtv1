/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:49:22 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:49:24 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

int				calc_color(t_obj *obj, double diffuse,
						int is_shadow, double specular)
{
	double		r;
	double		g;
	double		b;
	double		coef;
	double		s;

	s = specular + pow(specular, 400);
	if (obj->f->chosen == 1)
	{
		coef = s * diffuse * 70 * is_shadow + is_shadow * 10 * diffuse + 10;
		r = obj->color->r * coef;
		g = obj->color->g * coef;
		b = obj->color->b * coef;
	}
	else
	{
		coef = s * diffuse * 50 * is_shadow + is_shadow * 10 * diffuse + 20;
		r = obj->color->r * coef;
		g = obj->color->g * coef;
		b = obj->color->b * coef;
	}
	return ((obj->f->for_light) ?
			integrate_color(100, 100, 100) : integrate_color(r, g, b));
}
