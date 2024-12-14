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
