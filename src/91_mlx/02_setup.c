#include "minirt.h"

static void	ft_events_init(t_canvas *canvas)
{
	// mlx_hook(canvas->win, KeyPress, KeyPressMask, key_handler, canvas);
	// mlx_hook(canvas->win, ButtonPress, ButtonPressMask, mouse_handler, canvas);
	// mlx_hook(canvas->win, DestroyNotify, StructureNotifyMask, close_handler,
	// 	canvas);
	(void)canvas;
}

int	ft_setup(t_canvas *canvas)
{
	ft_mlx_init(canvas);
	// ft_data_init(canvas);
	ft_events_init(canvas);
	return (0);
}

