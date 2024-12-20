#include "minirt.h"

t_tuple	ft_reflect(t_tuple incoming, t_tuple normal)
{
	double	dot_res;
	t_tuple	res;

	dot_res = ft_dotprod_vector(incoming, normal);


	res = ft_scalar_tuple(normal, 2);
	res = ft_scalar_tuple(res, dot_res);
	res = ft_sub_tuple(incoming, res);

	return (res);
	// return (ft_sub_tuple(incoming, 
	// 				ft_scalar_tuple(ft_scalar_tuple(normal,
	// 			ft_dotprod_vector(incoming, normal)), 2)));
}
