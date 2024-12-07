#include "minirt.h"

t_tuple	ft_reflect(t_tuple incoming, t_tuple normal)
{
	return (ft_sub_tuple(incoming, ft_scalar_tuple(normal,
				ft_dotprod_vector(incoming, normal) * 2)));
}
