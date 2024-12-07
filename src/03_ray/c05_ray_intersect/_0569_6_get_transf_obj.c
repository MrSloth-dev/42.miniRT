#include "minirt.h"

void ft_get_transf_obj(t_shapes *s, t_tuple coord, t_tuple orientation, t_tuple scale)
{
	t_matrix translation;
	t_matrix scaled;
	// t_matrix rotation;

	translation = ft_create_transf_matrix(coord.x, coord.y, coord.z);
	scaled = ft_create_matrix(4, 4, 1);
	if (s->type != PLANE)
		scaled = ft_create_scale_matrix(scale.x, scale.y, scale.z);
	// if (s->type != SPHERE)
	(void)orientation; //rotation rotation rotation
	s->transform = ft_matrix_mult(translation, scaled);
	s->transposed = ft_transpose_matrix(s->transform);
	s->inverted = ft_invert_matrix(s->transform);
}
// t_matrix	ft_get_rotation_obj(t_tuple orientation)
// {
// 	t_maxtrix rotate_x;
// 	t_maxtrix rotate_y;
// 	t_maxtrix rotate_z;
//
// }
