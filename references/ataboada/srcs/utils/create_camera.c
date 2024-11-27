/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:30:54 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/23 12:09:14 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Initializes the t_camera structure with the specified values.
t_camera	*ft_create_camera(int hsize, int vsize, double fov)
{
	double		aspect;
	double		half_view;
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->fov = fov;
	half_view = tan(fov / 2);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / hsize;
	return (camera);
}
