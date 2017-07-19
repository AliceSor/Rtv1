/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:31:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/05/14 20:49:44 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_mlx			*create_win(void)
{
	t_mlx		*nw;

	nw = (t_mlx *)malloc(sizeof(t_mlx) + 100);
	if (nw)
	{
		nw->mlx = mlx_init();
		nw->win = mlx_new_window(nw->mlx, WIDTH - 1, HEIGHT - 2, "42");
		return (nw);
	}
	return (NULL);
}
