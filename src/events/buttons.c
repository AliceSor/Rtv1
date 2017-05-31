//
// Created by Alisa Soroka on 5/21/17.
//

#include "../../rtv1.h"

static void				put_image(t_rt *rt)
{
	mlx_destroy_image(rt->mlx->mlx, rt->mlx->im);
	create_image(rt->mlx);
	emit_rays(rt);
	mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->im, 0, 0);
}


int					destroy(void)
{
    exit(0);
}

int					buttons(int keycode, t_rt *rt)
{
	if (keycode == 123)
	{
		(rt->obj->next->next->s->center->x) -= 10;
		put_image(rt);
	}
    if (keycode == 124)
    {
        (rt->obj->next->next->s->center->x) += 10;
        put_image(rt);
    }
    if (keycode == 126)
    {
        (rt->obj->next->next->s->center->y) -= 10;
        put_image(rt);
    }
    if (keycode == 125)
    {
        (rt->obj->next->next->s->center->y) += 10;
        put_image(rt);
    }
    if (keycode == 78)
    {
        (rt->obj->next->next->s->center->y) += 100;
        put_image(rt);
    }
    if (keycode == 69)
    {
        (rt->obj->next->next->s->center->y) -= 100;
        put_image(rt);
    }
	if (keycode == 53)
		exit(0);
	return (0);

}


