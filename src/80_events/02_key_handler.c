#include "minirt.h"

int	key_handler(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Escape)
		close_handler(canvas);
	else if (keysym == XK_h)
		canvas->help = !canvas->help;
	if (keysym == XK_Shift_L)
		canvas->shift_press = -1;
	else if (ft_make_disco(keysym, canvas))
		;
	else if (ft_light_transform(keysym, canvas))
		;
	else if (ft_change_resolution(keysym, canvas))
		;
	else if (ft_change_obj_propriety(keysym, canvas, false))
		;
	else if (ft_camera_transform(keysym, canvas))
		;
	else if (keysym == XK_x)
		ft_clear_select(canvas);
	return (0);
}
