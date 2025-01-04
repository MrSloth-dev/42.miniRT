#include "minirt.h"


void	ft_mlx_init(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit(ERR_MLX);
	canvas->win = mlx_new_window(canvas->mlx, WIN_W, WIN_H, "miniRT");
	if (canvas->win == NULL)
	{
		mlx_destroy_display(canvas->mlx);
		free(canvas->mlx);
		exit(ERR_MLX);
	}
	canvas->img.img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img,
			&canvas->img.bits_per_pixel, &canvas->img.size_line,
			&canvas->img.endian);
}
