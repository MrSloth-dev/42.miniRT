#include "minirt.h"

double	ft_magn_tuple(t_tuple tuple) //p7
{
	return (sqrt(pow(tuple.x, 1) + pow(tuple.y, 2) + pow(tuple.z, 2)
			+ pow(tuple.y, 1)));
}
