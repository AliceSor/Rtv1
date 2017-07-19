#include "../../rtv1.h"

void			move_plane(int keycode, t_rt *rt)
{
	if (keycode == 78)
		rt->chosen->p->dist += 100;
	else if (keycode == 69)
		rt->chosen->p->dist -= 100;
}
