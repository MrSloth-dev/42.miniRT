#include "libft.h"
#include "minirt.h"
#include <unistd.h>


void	ft_mlx_end(t_canvas *canvas)
{
	mlx_do_key_autorepeatoff(canvas->mlx);
	mlx_hook(canvas->win, KeyPress, KeyPressMask, key_handler, canvas);
	mlx_hook(canvas->win, ButtonPress, ButtonPressMask, mouse_handler, canvas);
	mlx_hook(canvas->win, ButtonRelease, ButtonReleaseMask, mouse_handler_release, canvas);
	mlx_hook(canvas->win, MotionNotify, CWBackingStore, mouse_motion, canvas);
	mlx_hook(canvas->win, DestroyNotify, StructureNotifyMask, close_handler, canvas);
	mlx_hook(canvas->win, DestroyNotify, 0l, &close_handler, &canvas);
	mlx_loop_hook(canvas->mlx, ft_refreshframe, canvas);
	mlx_loop(canvas->mlx);
	ft_free_canvas(canvas);
}

int	main(int argc, char *argv[])
{
	t_canvas	canvas;

	if (argc != 2)
		return (ft_printf(2, "Error\n Argv!\n"), 1);
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return (1);
	if (DEBUG)
		return (0);
	ft_mlx_init(&canvas);
	ft_refreshframe(&canvas);
	ft_mlx_end(&canvas);
	return (0);
}
