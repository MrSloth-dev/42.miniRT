/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   51_camera_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:06:51 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_camera_transform(int keysym, t_canvas *canvas)
{
	if (keysym == XK_z)
	{
		canvas->camera.transf = canvas->camera.reset;
		canvas->camera.rotate = ft_create_matrix(4, 4, 1);
		canvas->camera.inv_rotate = ft_create_matrix(4, 4, 1);
	}
	if (keysym == XK_k && canvas->objects)
	{
		canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
				ft_add_tuple(canvas->camera.coord,
					ft_sub_tuple(((t_shapes *)canvas->objects->cont)->cyl.coord,
						canvas->camera.coord)),
				(t_tuple){0, 1, 0, 0});
		canvas->camera.rotate = ft_create_matrix(4, 4, 1);
		canvas->camera.inv_rotate = ft_create_matrix(4, 4, 1);
	}
	else if (!canvas->object_selected && !canvas->light_selected)
		ft_transform_camera_key(canvas, keysym);
	else
		return (false);
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	return (true);
}
