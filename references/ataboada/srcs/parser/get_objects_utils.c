/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:56:01 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/30 17:12:30 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_get_transform(t_shapes *s, t_point coord, t_vec3 orien, double diam)
{
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	scale;

	translate = ft_translation_matrix(coord.x, coord.y, coord.z);
	scale = ft_create_matrix(4, 4, YES);
	if (s->type != PLANE)
		scale = ft_scaling_matrix(diam, diam, diam);
	s->transform = ft_multiply_matrix(translate, scale);
	rotate = ft_create_matrix(4, 4, YES);
	if (s->type != SPHERE)
		rotate = ft_get_rotate(orien);
	s->transform = ft_multiply_matrix(s->transform, rotate);
	s->inverted = ft_invert_matrix(s->transform);
	s->transposed = ft_transpose_matrix(s->inverted);
}

t_matrix	ft_get_rotate(t_vec3 orien)
{
	t_matrix	rotate_y;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate = ft_create_matrix(4, 4, YES);
	if (orien.x)
		rotate = ft_rotation_matrix('z', orien.x * M_PI / 2);
	if (orien.y)
	{
		rotate_y = ft_rotation_matrix('y', orien.y * M_PI / 2);
		if (orien.x)
			rotate = ft_multiply_matrix(rotate, rotate_y);
		else
			rotate = rotate_y;
	}
	if (orien.z)
	{
		rotate_z = ft_rotation_matrix('x', orien.z * M_PI / 2);
		if (orien.x || orien.y)
			rotate = ft_multiply_matrix(rotate, rotate_z);
		else
			rotate = rotate_z;
	}
	return (rotate);
}
