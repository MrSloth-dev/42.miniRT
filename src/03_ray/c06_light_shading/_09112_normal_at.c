#include "minirt.h"

t_tuple	ft_normal_at_plane(t_shapes *shape)
{
	t_tuple	o_normal;
	t_tuple	w_normal;

	o_normal = (t_tuple){0, 1, 0 ,0};
	w_normal = ft_mult_matrix_tuple(ft_transpose_matrix(shape->inverted),
			o_normal);
	w_normal.w = 0;
	return (ft_norm_vector(w_normal));
}

t_tuple	ft_normal_at(t_shapes *shape, t_tuple w_point)
{
	if (shape->type == SPHERE)
		return (ft_normal_at_sph(shape, w_point));
	if (shape->type == PLANE)
		return (ft_normal_at_plane(shape));
	return ((t_tuple){0});
}
