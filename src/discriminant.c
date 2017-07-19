/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:25:54 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/19 17:25:56 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int			discriminant(double *t, t_abc abc)
{
	abc.d = abc.b * abc.b - 4 * abc.a * abc.c;
	if (abc.d < 0)
		return (0);
	abc.c = sqrt(abc.d);
	abc.t0 = (-abc.b + abc.c) / (2 * abc.a);
	abc.t1 = (-abc.b - abc.c) / (2 * abc.a);
	if (abc.t0 < 0.001f && abc.t1 < 0.001f)
		return (0);
	else if (abc.t0 > 0.001f && abc.t1 > 0.001f && abc.t0 > abc.t1)
		abc.t0 = abc.t1;
	else if (abc.t0 < 0.001f)
		abc.t0 = abc.t1;
	if (abc.t0 > 0.001f)
	{
		*t = abc.t0;
		return (1);
	}
	return (0);
}
