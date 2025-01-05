#include "minirt.h"

bool	ft_light_transform(int keysym, t_canvas *canvas)
{
	if (keysym == XK_l)
	{
		if (canvas->object_selected)
			ft_clear_select(canvas);
		canvas->light_selected = 1;
		return (true);
	}
	else if (canvas->light_selected == 1)
	{
		if (ft_change_light_position(keysym, canvas))
			;
		else if (ft_change_light_color(keysym, canvas))
			;
		else
			return (false);
		return (true);
	}
	return (false);
}
