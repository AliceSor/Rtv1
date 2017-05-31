#include "../rtv1.h"

int				main(void)
{
	t_rt		*rt;
	t_obj		*obj;

	rt = (t_rt *)malloc(sizeof(t_rt) + 1);
	rt->mlx = create_win();
	create_image(rt->mlx);
	rt->screen = init_pos_screen();
	fill_objects(rt);

	obj = rt->obj;
	while (obj)
	{
		printf("%d", obj->type_obj);
		obj = obj->next;
	}


	emit_rays(rt);
	mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->im, -1, -1);
	mlx_hook(rt->mlx->win, 2, 5, buttons, rt);
	mlx_hook(rt->mlx->win, 17, 0, destroy, 0);
	mlx_loop(rt->mlx->mlx);
	return (0);
}
