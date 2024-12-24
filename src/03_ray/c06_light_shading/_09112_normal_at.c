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

t_tuple	ft_normal_at_cyl(t_shapes *shape, t_tuple w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;

	//need to correct this
	o_point = ft_mult_matrix_tuple(shape->inverted, w_point);
	o_normal = ft_sub_tuple(o_point, (t_tuple){0});
	w_normal = (t_tuple){o_normal.x, 0, o_normal.z, 0}; 
	w_normal.w = 0;
	return (ft_norm_vector(w_normal));
}

t_tuple	ft_normal_at(t_shapes *shape, t_tuple w_point)
{
	if (shape->type == SPHERE)
		return (ft_normal_at_sph(shape, w_point));
	if (shape->type == PLANE)
		return (ft_normal_at_plane(shape));
	if (shape->type == CYLINDER)
		return (ft_normal_at_cyl(shape, w_point)); //WTF IS GOING ON?!?
	return ((t_tuple){0});
}
