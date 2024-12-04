#include "minirt.h"

double	ft_magn_tuple(t_tuple tuple) //p7
{
	return (sqrt(tuple.x * tuple.x + tuple.y * tuple.y + tuple.z * tuple.z
			 + tuple.w * tuple.w));
}
