/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_create_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:24:36 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:24:36 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_plane(t_canvas *canvas, char **split)
{
	t_shapes	*shape;

	shape = ft_create_default_shape(PLANE);
	shape->pla.coord = ft_get_coord(split[1], "Plane", canvas);
	shape->material.color = ft_get_color(split[3], "Plane", canvas);
	shape->pla.norm = ft_get_norm(split[2], "Plane", canvas);
	if (shape->pla.norm.w == -1
		|| shape->pla.coord.w == -1
		|| shape->material.color.w == -1)
		return (ft_free(shape), 0);
	shape->material.color = ft_scalar_tuple(shape->material.color, 1 / 255.f);
	if (ft_is_tuples_equal(shape->pla.norm, (t_tuple){0}))
		shape->pla.norm = (t_tuple){0, 1, 0, 0};
	ft_get_transf_obj(shape, shape->pla.coord, shape->pla.norm,
		(t_tuple){1, 1, 1, 0});
	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_cylinder(t_canvas *canvas, char **split)
{
	t_shapes	*shape;

	shape = ft_create_default_shape(CYLINDER);
	shape->cyl.coord = ft_get_coord(split[1], "Cylinder", canvas);
	shape->material.color = ft_get_color(split[5], "Cylinder", canvas);
	shape->cyl.norm = ft_get_norm(split[2], "Cylinder", canvas);
	shape->cyl.size.diameter = ft_get_double(split[3], "Cylinder diameter",
			canvas) / 2;
	shape->cyl.size.height = ft_get_double(split[4], "Cylinder height", canvas);
	if (shape->cyl.coord.w == -1 || shape->cyl.norm.w == -1
		|| shape->material.color.w == -1
		||shape->cyl.size.height == -43.42 || shape->cyl.size.height <= 0
		||shape->cyl.size.diameter == -43.42 || shape->cyl.size.diameter <= 0)
		return (ft_free(shape), 0);
	shape->material.color = ft_scalar_tuple(shape->material.color, 1 / 255.f);
	shape->cyl.size.max = shape->cyl.size.height / 2;
	shape->cyl.size.min = -shape->cyl.size.height / 2;
	ft_get_transf_obj(shape, shape->cyl.coord, shape->cyl.norm,
		(t_tuple){shape->cyl.size.diameter, shape->cyl.size.diameter,
		shape->cyl.size.diameter, 0});
	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
	return (1);
}
