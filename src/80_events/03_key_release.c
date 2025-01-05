#include "minirt.h"

int	key_release(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Shift_L)
		canvas->shift_press = 1;
	return (0);
}
