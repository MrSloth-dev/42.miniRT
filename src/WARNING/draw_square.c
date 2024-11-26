#include "minirt.h"

void	ft_draw_square(t_canvas *canvas,t_tuple start, t_tuple sides, int color)
{
	int	y;
	int	x;

	if (!canvas)
		return ;
	ft_refreshframe(canvas);
	y = start.y;
	x = start.x;
	while (y < (int)(sides.x + start.y))
	{
		while (x < (int)(sides.x + start.x))
		{
			ft_pixel_put(canvas->img, x, y, color);
			x++;
		}
		x = start.x;
		y++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}

