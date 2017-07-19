/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:15:10 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 17:15:26 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

int			identify_obj(t_v *d, t_v *p0, t_obj *obj, double *t)
{
	if (obj->type_obj == 0 && obj->f->is_visible)
		return (intersect_sphere(d, p0, obj->s, t));
	else if (obj->type_obj == 1 && obj->f->is_visible)
		return (intersect_plane(d, p0, obj->p, t));
	else if (obj->type_obj == 2 && obj->f->is_visible)
		return (intersect_cylinder(d, p0, obj->cl, t));
	else if (obj->type_obj == 3 && obj->f->is_visible)
		return (intersect_cone(d, p0, obj->cn, t));
	else
		return (0);
}
