#include "minirt.h"
//negative
t_tuple	ft_neg_tuple(t_tuple tuple)
{
	return ((t_tuple){-tuple.x, -tuple.y, -tuple.z, -tuple.w});
}
