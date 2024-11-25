#include "minirt.h"

t_tuple	ft_norm_vector(t_tuple tuple)//p10
{
	ft_assert(tuple.w == 0, "Not a Vector");
	return ((t_tuple){tuple.x / ft_magn_tuple(tuple),
		tuple.y / ft_magn_tuple(tuple),
		tuple.z / ft_magn_tuple(tuple), 1});
}
