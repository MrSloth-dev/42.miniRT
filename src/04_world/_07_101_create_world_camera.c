/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   101_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:58:30 by isilva-t          #+#    #+#             */
/*   Updated: 2024/12/14 13:58:35 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	ft_create_world_camera(double h_size, double v_size, double field_v)
{
	t_camera	cam;
	double		aspect;

	cam.h_size = h_size;
	cam.v_size = v_size;
	cam.field_v = field_v;
	cam.transf = ft_create_matrix(4, 4, 1);
	cam.inverted = ft_invert_matrix(cam.transf);
	cam.half_view = tan(cam.field_v / 2);
	aspect = cam.h_size / cam.v_size;
	if (aspect >= 1)
	{
		cam.half_width = cam.half_view;
		cam.half_height = cam.half_view / aspect;
	}
	else
	{
		cam.half_width = cam.half_view * aspect;
		cam.half_height = cam.half_view;
	}
	cam.px_size = (cam.half_width * 2) / cam.h_size;
	return (cam);
}

void	ft_create_world_camera_test(double h_size, double v_size, t_canvas *canvas)
{
	double		aspect;

	canvas->camera.h_size = h_size;
	canvas->camera.v_size = v_size;
	canvas->camera.field_v = canvas->camera.fov; //COPYED DATA OF SAME STRUCT HERE
	canvas->camera.transf = ft_create_matrix(4, 4, 1);
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	canvas->camera.half_view = tan(canvas->camera.field_v / 2);
	aspect = canvas->camera.h_size / canvas->camera.v_size;
	if (aspect >= 1)
	{
		canvas->camera.half_width = canvas->camera.half_view;
		canvas->camera.half_height = canvas->camera.half_view / aspect;
	}
	else
	{
		canvas->camera.half_width = canvas->camera.half_view * aspect;
		canvas->camera.half_height = canvas->camera.half_view;
	}
	canvas->camera.px_size = (canvas->camera.half_width * 2) / canvas->camera.h_size;
}
