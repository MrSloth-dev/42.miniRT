/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_create_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:49:31 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:09:16 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minirt.h"
#include <math.h>

t_shapes	*ft_create_default_shape(int type)
{
	t_shapes	*new;

	new = malloc(sizeof(t_shapes));
	*new = (t_shapes){0};
	new->type = type;
	new->material = ft_create_material();
	new->inverted = ft_create_matrix(4, 4, 1);
	new->transposed = ft_create_matrix(4, 4, 1);
	new->transform = ft_create_matrix(4, 4, 1);
	new->rotate = ft_create_matrix(4, 4, 1);
	new->inv_rotate = ft_create_matrix(4, 4, 1);
	return (new);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_ambient(t_canvas *canvas, char **split)
{
	canvas->ambient.ratio = ft_get_double(split[1], "Ambient", canvas);
	if (canvas->ambient.ratio < 0 || canvas->ambient.ratio > 1)
		return (ft_printf(2, "Error\nAmbient value is out of bounds[0,1]\n"),
			0);
	canvas->ambient.color = ft_get_color(split[2], "Ambient", canvas);
	if (canvas->ambient.color.w == -1)
		return (0);
	canvas->ambient.color
		= ft_scalar_tuple(ft_scalar_tuple(canvas->ambient.color,
				canvas->ambient.ratio), 0.1f / 25.5f);
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_light(t_canvas *canvas, char **split)
{
	t_light	light;
	double	bright;

	bright = ft_get_double(split[2], "Light", canvas);
	if (bright != -43.42 && (bright < 0 || bright > 1))
		return (ft_printf(2, "Error\nLight value is out of bounds[0,1]\n"), 0);
	else if (bright == -43.42)
		return (0);
	light.coord = ft_get_coord(split[1], "Light", canvas);
	light.color = ft_get_color(split[3], "Light", canvas);
	if (light.color.w == -1 || light.coord.w == -1)
		return (0);
	light.color = ft_scalar_tuple(light.color, bright);
	light.color = ft_scalar_tuple(light.color, 1.0f / 25.5f);
	light.intensity = ft_scalar_tuple(light.color, bright / 90);
	canvas->light = light;
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_camera(t_canvas *canvas, char **split)
{
	canvas->camera.rotate = ft_create_matrix(4, 4, 1);
	canvas->camera.inv_rotate = ft_create_matrix(4, 4, 1);
	canvas->camera.coord = ft_get_coord(split[1], "Camera", canvas);
	canvas->camera.norm = ft_get_norm(split[2], "Camera", canvas);
	if (canvas->camera.coord.w == -1 || canvas->camera.norm.w == -1)
		return (0);
	canvas->camera.field_v = ft_get_double(split[3], "Camera fov", canvas);
	if (canvas->camera.field_v == -42.43 || canvas->camera.field_v < 1
		|| canvas->camera.field_v > 180)
		return (ft_printf(2, "Invalid Camera field of view"), 0);
	canvas->camera.field_v *= M_PI / 180;
	ft_create_world_camera(IMG_W, IMG_H, canvas);
	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
			ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
			(t_tuple){0, 1, 0, 0});
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	canvas->camera.reset = canvas->camera.transf;
	return (1);
}

/**
 * @brief 
 *
 * @param canvas 
 * @param split splitted line
 * @return 1 if valid 0 if not valid
 */
int	ft_create_sphere(t_canvas *canvas, char **split)
{
	t_shapes	*shape;

	shape = ft_create_default_shape(SPHERE);
	shape->sph.coord = ft_get_coord(split[1], "Sphere", canvas);
	shape->material.color = ft_get_color(split[3], "Sphere", canvas);
	shape->sph.diameter = ft_get_double(split[2], "Sphere diam.", canvas) / 2;
	if (shape->sph.coord.w == -1
		|| shape->material.color.w == -1
		|| shape->sph.diameter == -43.42
		|| shape->sph.diameter <= 0)
		return (ft_free(shape), 0);
	shape->material.color = ft_scalar_tuple(shape->material.color,
			1.0f / 255.0f);
	ft_get_transf_obj(shape, shape->sph.coord, (t_tuple){0},
		(t_tuple){shape->sph.diameter, shape->sph.diameter,
		shape->sph.diameter, 0});
	ft_lstadd_back(&canvas->objects, ft_lstnew(shape));
	return (canvas->count.sphere++, 1);
}
