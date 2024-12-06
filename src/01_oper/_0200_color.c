#include "minirt.h"

int	ft_color_rgb_to_int(t_color color)
{
	return ((int)(color.x) << 16
	| (int)(color.y) << 8
	| (int)(color.z));
}

t_color	ft_color_int_to_rgb(int color)
{
	t_color	col;

	col.x = (float)(color >> 16) / 255.0f;
	col.y = (float)(color >> 8) / 255.0f;
	col.z = (float)color / 255.0f;
	return (col);
}

int	ft_get_mlx_color(t_color color)
{
	if (color.x > 10)
		color.x = 10;
	if (color.y > 10)
		color.y = 10;
	if (color.z > 10)
		color.z = 10;
	return ((int)(color.x * 25.5f) << 16
	| (int)(color.y * 25.5f) << 8
	| (int)(color.z * 25.5f));
}
