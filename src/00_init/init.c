#include "libft.h"
#include "minirt.h"

void	ft_init_canvas(t_canvas *canvas)
{
	(void)canvas;
	*canvas = (t_canvas){0};

	if (STEP > 19 || STEP < 1)
		canvas->step = 19;
	else
		canvas->step = STEP;
	canvas->mouse_prev_x = -1;
	canvas->mouse_prev_y = -1;
}
