#include "minirt.h"
//negative
t_tuple	ft_neg_tuple(t_tuple tuple)
{
	t_tuple	result;

	result.w = tuple.w;
	result.x = - tuple.x;
	result.y = - tuple.y;
	result.z = - tuple.z;
	return (result);
}
