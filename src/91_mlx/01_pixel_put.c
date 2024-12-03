#include "minirt.h"

void	ft_pixel_put(t_img *data, int x, int y, int color)
{
	char	*pxl;

	if (x < IMG_WIDTH && y < IMG_HEIGHT && x > 0 && y > 0)
	{
		pxl = data->addr + (y * data->size_line + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}
