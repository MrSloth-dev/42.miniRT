#include "minirt.h"

int	ft_free_mlx(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	return (1);
}
