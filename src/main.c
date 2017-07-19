#include "../rtv1.h"

int				main(void)
{
	t_rt		*rt;
	t_obj		*obj;

	rt = (t_rt *)malloc(sizeof(t_rt) + 50);// malloc
	rt->costul = 0;
	rt->mlx = create_win();//malloc
	create_image(rt->mlx);
	rt->screen = init_pos_screen(rt);/*malloc*/
	fill_objects(rt);
	rt->chosen = rt->obj;
	rt->chosen->f->chosen = 1;
	rt->speed = 1;
	rt->speed_move = 10;
	rt->speed_rotate = 5;
	rt->is_light = 1;
	rt->hit_point = (t_v *)malloc(sizeof(t_v) + 1);
	rt->light_ray = (t_v *)malloc(sizeof(t_v) + 1);
	rt->temp_sub = (t_v *)malloc(sizeof(t_v) + 1);
//    if (rt->mlx->mlx && rt->mlx->win && rt->mlx->im)
//    {
		ray_trace(rt);
		mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->im, -1, -1);
		mlx_hook(rt->mlx->win, 2, 5, buttons, rt);
		mlx_hook(rt->mlx->win, 17, 0, destroy, 0);
			mlx_loop(rt->mlx->mlx);
//    }
		free(rt);
	return (0);
}
