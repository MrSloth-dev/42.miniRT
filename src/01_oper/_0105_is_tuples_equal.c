#include "minirt.h"

int	ft_is_tuples_equal(t_tuple tuple1, t_tuple tuple2)
{
	if (tuple1.w != tuple2.w
	 	|| !ft_is_float_equal(tuple1.x, tuple2.x)
	 	|| !ft_is_float_equal(tuple1.y, tuple2.y)
	 	|| !ft_is_float_equal(tuple1.z, tuple2.z))
		return (0);
	return (1);
}
