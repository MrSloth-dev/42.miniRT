#include "minirt.h"

t_tuple	ft_scalar_tuple(t_tuple tuple, double value)
{
	t_tuple	result;

	result.w = tuple.w;
	result.x = tuple.x * value;
	result.y = tuple.y * value;
	result.z = tuple.z * value;
	return (result);
}
