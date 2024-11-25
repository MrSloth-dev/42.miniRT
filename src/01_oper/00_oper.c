#include "minirt.h"

void	ft_tuple_init(t_tuple *tuple, t_point coord, int w)
{
	ft_assert((w == T_POINT || w == T_VECTOR), "Invalid tuple w!\n");
	tuple->w = w;
	tuple->x = coord.x;
	tuple->y = coord.y;
	tuple->z = coord.z;
}

t_tuple	ft_mul_tuple(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	result;

	if (tuple1.w || tuple2.w)
		result.w = 1;
	else
		result.w = 0;
	result.x = tuple1.x * tuple2.x;
	result.y = tuple1.y * tuple2.y;
	result.z = tuple1.z * tuple2.z;
	return (result);
}

int	ft_color_rgb_to_int(t_color color)
{
	return ((int)(color.r * 255.0f) << 16
	| (int)(color.g * 255.0f) << 8
	| (int)(color.g * 255.0f));
}

t_color	ft_color_int_to_rgb(int color)
{
	t_color	col;

	col.r = (float)(color >> 16) / 255.0f;
	col.r = (float)(color >> 8) / 255.0f;
	col.r = (float)color / 255.0f;
	return (col);
}
