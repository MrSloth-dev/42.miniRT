#include "minirt.h"

t_tuple	ft_normal_at_sph(t_shapes *shape, t_tuple w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;

	o_point = ft_mult_matrix_tuple(shape->inverted, w_point);
	o_normal = ft_sub_tuple(o_point, (t_tuple){0});
	w_normal = ft_mult_matrix_tuple(ft_transpose_matrix(shape->inverted),
			o_normal);
	w_normal.w = 0;
	return (ft_norm_vector(w_normal));
}
