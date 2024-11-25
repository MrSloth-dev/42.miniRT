#include "minirt.h"
//subtract
t_tuple	ft_sub_tuple(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	result;

	result.x = tuple1.x - tuple2.x;
	result.y = tuple1.y - tuple2.y;
	result.z = tuple1.z - tuple2.z;
	result.w = tuple1.w - tuple2.w;
	return (result);
}
