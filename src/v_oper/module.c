/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:52:38 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 14:52:39 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

double				module(t_v *v)
{
	double			res;

	res = 0;
	if (v)
		res = sqrt(scalar_mult(v, v));
	return (res);
}
