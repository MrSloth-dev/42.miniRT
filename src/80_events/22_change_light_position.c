#include "minirt.h"

bool	ft_change_light_position(int keysym, t_canvas *canvas)
{
	if (keysym == XK_w)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, 0.2, 0, 0});
	else if (keysym == XK_s)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, -0.2, 0, 0});
	else if (keysym == XK_a)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){-0.2, 0, 0, 0});
	else if (keysym == XK_d)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0.2, 0, 0, 0});
	else if (keysym == XK_q)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, 0, 0.2, 0});
	else if (keysym == XK_e)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, 0, -0.2, 0});
	else
		return (false);
	return (true);
}
