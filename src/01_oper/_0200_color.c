#include "minirt.h"

int	ft_color_rgb_to_int(t_color color)
{
	return ((int)(color.x * 255.0f) << 16
	| (int)(color.y * 255.0f) << 8
	| (int)(color.z * 255.0f));
}

t_color	ft_color_int_to_rgb(int color)
{
	t_color	col;

	col.x = (float)(color >> 16) / 255.0f;
	col.y = (float)(color >> 8) / 255.0f;
	col.z = (float)color / 255.0f;
	return (col);
}
