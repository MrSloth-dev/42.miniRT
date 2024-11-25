#include "minirt.h"

int	ft_floatcmp(double num1, double num2) //p5
{
	if (fabs(num1 - num2) < ROUND_ERROR)
		return (1);
	else
		return (0);
}

void	ft_tuple_init(t_tuple *tuple, t_point coord, int w)
{
	ft_assert((w == T_POINT || w == T_VECTOR), "Invalid tuple w!\n");
	tuple->w = w;
	tuple->x = coord.x;
	tuple->y = coord.y;
	tuple->z = coord.z;
}

t_tuple	ft_add_tuple(t_tuple tuple1, t_tuple tuple2) //p6
{
	t_tuple	result;

	result.w = tuple1.w + tuple2.w;
	result.x = tuple1.x + tuple2.x;
	result.y = tuple1.y + tuple2.y;
	result.z = tuple1.z + tuple2.z;
	return (result);
}

t_tuple	ft_sub_tuple(t_tuple tuple1, t_tuple tuple2) //p6
{
	t_tuple	result;

	result.x = tuple1.x - tuple2.x;
	result.y = tuple1.y - tuple2.y;
	result.z = tuple1.z - tuple2.z;
	result.w = tuple1.w - tuple2.w;
	return (result);
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

t_tuple	ft_scalar_tuple(t_tuple tuple, double value)//p8
{
	t_tuple	result;

	result.w = tuple.w;
	result.x = tuple.x * value;
	result.y = tuple.y * value;
	result.z = tuple.z * value;
	return (result);
}

t_tuple	ft_neg_tuple(t_tuple tuple) //p7
{
	t_tuple	result;

	result.w = tuple.w;
	result.x = - tuple.x;
	result.y = - tuple.y;
	result.z = - tuple.z;
	return (result);
}

double	ft_magn_tuple(t_tuple tuple) //p8
{
	return (sqrt(pow(tuple.x, 2) + pow(tuple.y, 2) + pow(tuple.z, 2)
			+ pow(tuple.y, 2)));
}

t_tuple	ft_norm_vector(t_tuple tuple)//p10
{
	ft_assert(tuple.w == 0, "Not a Vector");
	return ((t_tuple){tuple.x / ft_magn_tuple(tuple),
		tuple.y / ft_magn_tuple(tuple),
		tuple.z / ft_magn_tuple(tuple), 1});
}

double	ft_dotprod_vector(t_tuple a, t_tuple b)//p10
{
	ft_assert(a.w == 0, "a is Not a Vector: dotprod");
	ft_assert(b.w == 0, "b is Not a Vector: dotprod");
	return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w);
}

t_tuple	ft_crossprod_vector(t_tuple a, t_tuple b)//p11
{
	ft_assert(a.w == 0, "a is Not a Vector: crossprod");
	ft_assert(b.w == 0, "b is Not a Vector: crossprod");
	return ((t_tuple){a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		T_VECTOR});
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
