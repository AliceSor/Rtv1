#include "../../rtv1.h"

void				change_speed(int keycode, t_rt *rt)
{
	if (keycode == 92)
		rt->speed_move += 10;
	else if (keycode == 85)
		rt->speed_move -= 10;
	else if (keycode == 82)
		rt->speed_rotate -= 5;
	else if (keycode == 65)
		rt->speed_rotate += 5;
	else if (keycode == 76)
		(rt->speed)++;
    else if (keycode == 67 && rt->speed > 1)
		(rt->speed)--;
}
