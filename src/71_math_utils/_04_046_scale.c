#include "minirt.h"

t_tuple	ft_scale(t_tuple scale, t_tuple to_scale)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{scale.x, 0, 0, 0},
	{0, scale.y, 0, 0},
	{0, 0, scale.z, 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, to_scale));
}
