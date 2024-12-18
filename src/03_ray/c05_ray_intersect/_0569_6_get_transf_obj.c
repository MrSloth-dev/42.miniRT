#include "minirt.h"

t_matrix	ft_get_rotation_obj(t_tuple orientation)
{
	t_matrix rotate;

	rotate = ft_create_matrix(4, 4, 1);
	if (orientation.x)
		rotate = ft_matrix_mult(rotate, ft_rotate_matrix_x(orientation.x));
	if (orientation.y)
			rotate = ft_matrix_mult(rotate, ft_rotate_matrix_y(orientation.y));
	if (orientation.z)
		rotate = ft_matrix_mult(rotate, ft_rotate_matrix_z(orientation.z));
	return (rotate);
}

void ft_get_transf_obj(t_shapes *s, t_tuple coord, t_tuple orientation, t_tuple scale)
{
	t_matrix translation;
	t_matrix scaled;
	t_matrix rotation;

	scaled = ft_create_matrix(4, 4, 1);
	translation = ft_translation_matrix(coord.x, coord.y, coord.z);
	rotation = ft_create_matrix(4, 4, 1);
	if (s->type != PLANE)
		scaled = ft_scale_matrix(scale.x, scale.y, scale.z);
	if (s->type != SPHERE)
		rotation = ft_get_rotation_obj(orientation);
	s->transform = ft_matrix_mult(translation, ft_matrix_mult(rotation, scaled));
	s->transposed = ft_transpose_matrix(s->transform);
	s->inverted = ft_invert_matrix(s->transform);
}

