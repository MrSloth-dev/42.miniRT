/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _09_112_normal_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// chapter 6, page 78
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

t_tuple	ft_normal_at_plane(t_shapes *shape)
{
	t_tuple	o_normal;
	t_tuple	w_normal;

	o_normal = (t_tuple){0, 1, 0, 0};
	w_normal = ft_mult_matrix_tuple(ft_transpose_matrix(shape->inverted),
			o_normal);
	w_normal.w = 0;
	return (ft_norm_vector(w_normal));
}

// "dist" var is used for norm vector when point it's in a cap of cylinder
t_tuple	ft_normal_at_cyl(t_shapes *shape, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;
	double	dist;

	object_point = ft_mult_matrix_tuple(shape->inverted, world_point);
	dist = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dist < 1 && object_point.y >= (shape->cyl.size.max - ROUND_ERROR))
		object_normal = (t_tuple){0, 1, 0, 0};
	else if (dist < 1 && object_point.y <= (shape->cyl.size.min + ROUND_ERROR))
		object_normal = (t_tuple){0, -1, 0, 0};
	else
		object_normal = (t_tuple){object_point.x, 0, object_point.z, 0};
	world_normal = ft_mult_matrix_tuple(ft_transpose_matrix(shape->inverted),
			object_normal);
	world_normal.w = 0;
	return (ft_norm_vector(world_normal));
}

t_tuple	ft_normal_at(t_shapes *shape, t_tuple w_point)
{
	if (shape->type == SPHERE)
		return (ft_normal_at_sph(shape, w_point));
	if (shape->type == PLANE)
		return (ft_normal_at_plane(shape));
	if (shape->type == CYLINDER)
		return (ft_normal_at_cyl(shape, w_point));
	return ((t_tuple){0});
}
