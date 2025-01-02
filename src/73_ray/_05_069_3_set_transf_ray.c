#include "minirt.h"

t_ray	ft_set_transf_ray(t_ray ray, t_matrix inverted)
{
	t_ray	temp;

	temp.pos = ft_mult_matrix_tuple(inverted, ray.pos);
	temp.dir = ft_mult_matrix_tuple(inverted, ray.dir);
	return (temp);
}
