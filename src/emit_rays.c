/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:57:40 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/19 18:57:48 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void        emit_rays(t_rt *rt)
{
    int     i;
//    t_v     *p;
    t_v     *d;
    int     color;

    i = -1;
//    p = rt->screen->points;
    d = rt->screen->directions;
    while (++i < WIDTH * HEIGHT - 10)
    {
        color = intersect(rt, &(d[i]));
//        printf("[i: %d, %d]\n", i, color);
        put_pixel(i, color, rt->mlx);
//        write(1,".", 1);
    }
    put_pixel(200000, 0xFFFFFF, rt->mlx);
    put_pixel(2000, 0xFF00FF, rt->mlx);
}
