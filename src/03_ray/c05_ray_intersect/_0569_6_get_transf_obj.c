#include "minirt.h"

t_matrix	ft_get_rotation_obj(t_tuple orientation)
{
	t_matrix rotate;
	t_matrix rotate_y;
	t_matrix rotate_z;

	rotate = ft_create_matrix(4, 4, 1);
	if (orientation.x)
		rotate = ft_matrix_mult(rotate, ft_rotate_matrix_x(orientation.x));
	if (orientation.y)
	{
		rotate_y = ft_rotate_matrix_y(orientation.y);
		if (orientation.x)
			rotate = ft_matrix_mult(rotate, ft_rotate_matrix_y(orientation.y));
		else
			rotate = rotate_y;
	}
	if (orientation.z)
	{
		rotate_z = ft_rotate_matrix_z(orientation.z);
		if (orientation.x || orientation.y)
			rotate = ft_matrix_mult(rotate, ft_rotate_matrix_z(orientation.z));
		else
			rotate = rotate_z;
	}
	return (rotate);
}

void ft_get_transf_obj(t_shapes *s, t_tuple coord, t_tuple orientation, t_tuple scale)
{
	t_matrix translation;
	t_matrix scaled;
	t_matrix rotation;

	translation = ft_translation_matrix(coord.x, coord.y, coord.z);
	scaled = ft_create_matrix(4, 4, 1);
	rotation = ft_create_matrix(4, 4, 1);
	if (s->type != PLANE)
		scaled = ft_scale_matrix(scale.x, scale.y, scale.z);
	if (s->type != SPHERE)
		rotation = ft_get_rotation_obj(orientation);
	s->transform = ft_matrix_mult(ft_matrix_mult(translation, rotation), scaled);
	s->transposed = ft_transpose_matrix(s->transform);
	s->inverted = ft_invert_matrix(s->transform);
}

