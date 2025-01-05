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

void	ft_update_world_camera(t_canvas *canvas)
{
	canvas->camera.half_view = tan(canvas->camera.field_v / 2);
	if (canvas->camera.aspect >= 1)
	{
		canvas->camera.half_width = canvas->camera.half_view;
		canvas->camera.half_height = canvas->camera.half_view
			/ canvas->camera.aspect;
	}
	else
	{
		canvas->camera.half_width = canvas->camera.half_view
			* canvas->camera.aspect;
		canvas->camera.half_height = canvas->camera.half_view;
	}
	canvas->camera.px_size
		= (canvas->camera.half_width * 2) / canvas->camera.h_size;
}

void	ft_create_world_camera(double h_size, double v_size, t_canvas *canvas)
{
	canvas->camera.h_size = h_size;
	canvas->camera.v_size = v_size;
	canvas->camera.transf = ft_create_matrix(4, 4, 1);
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	canvas->camera.half_view = tan(canvas->camera.field_v / 2);
	canvas->camera.aspect = canvas->camera.h_size / canvas->camera.v_size;
	if (canvas->camera.aspect >= 1)
	{
		canvas->camera.half_width = canvas->camera.half_view;
		canvas->camera.half_height = canvas->camera.half_view
			/ canvas->camera.aspect;
	}
	else
	{
		canvas->camera.half_width = canvas->camera.half_view
			* canvas->camera.aspect;
		canvas->camera.half_height = canvas->camera.half_view;
	}
	canvas->camera.px_size
		= (canvas->camera.half_width * 2) / canvas->camera.h_size;
}
