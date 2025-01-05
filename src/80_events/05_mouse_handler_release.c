#include "minirt.h"

int	mouse_handler_release(int mousecode, int x, int y, t_canvas *canvas)
{
	(void)x;
	(void)y;
	if (mousecode == 3)
		canvas->mouse_drag = 0;
	return (0);
}
