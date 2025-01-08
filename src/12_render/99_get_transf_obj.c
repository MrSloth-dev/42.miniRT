/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_get_transf_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_get_rotation_obj(t_tuple orien)
{
	t_matrix	rotate_y;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate = ft_create_matrix(4, 4, 1);
	if (orien.x)
		rotate = ft_rotate_matrix_z(orien.x * M_PI / 2);
	if (orien.y)
	{
		rotate_y = ft_rotate_matrix_y(orien.y * M_PI / 2);
		if (orien.x)
			rotate = ft_matrix_mult(rotate, rotate_y);
		else
			rotate = rotate_y;
	}
	if (orien.z)
	{
		rotate_z = ft_rotate_matrix_x(orien.z * M_PI / 2);
		if (orien.x || orien.y)
			rotate = ft_matrix_mult(rotate, rotate_z);
		else
			rotate = rotate_z;
	}
	return (rotate);
}

static void	ft_setup_vars(t_matrix *translation, t_matrix *scaled,
					t_matrix *rotation, t_tuple *coord)
{
	*scaled = ft_create_matrix(4, 4, 1);
	*translation = ft_translation_matrix(coord->x, coord->y, coord->z);
	*rotation = ft_create_matrix(4, 4, 1);
}

void	ft_get_transf_obj(t_shapes *s, t_tuple coord,
				t_tuple orientation, t_tuple scale)
{
	t_matrix	translation;
	t_matrix	scaled;
	t_matrix	rotation;

	ft_setup_vars(&translation, &scaled, &rotation, &coord);
	if (s->type != PLANE)
		scaled = ft_scale_matrix(scale.x, scale.y, scale.z);
	if (s->type != SPHERE)
	{
		rotation = ft_get_rotation_obj(orientation);
		s->rotate = ft_matrix_mult(s->rotate, rotation);
		s->inv_rotate = ft_invert_matrix(s->rotate);
	}
	s->transform = ft_matrix_mult(s->transform, translation);
	s->transform = ft_matrix_mult(s->transform, rotation);
	s->transform = ft_matrix_mult(s->transform, scaled);
	s->transposed = ft_transpose_matrix(s->transform);
	s->inverted = ft_invert_matrix(s->transform);
}
