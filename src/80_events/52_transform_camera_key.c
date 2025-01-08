/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   52_transform_camera_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:06:27 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	ft_camera_wasd_keys(t_camera *camera, int key)
{
	if (key != XK_a && key != XK_d && key != XK_w && key != XK_s)
		return (false);
	camera->transf = ft_matrix_mult(camera->transf, camera->inv_rotate);
	if (key == XK_a)
		camera->transf = ft_matrix_mult(camera->transf,
				ft_translation_matrix(1, 0, 0));
	else if (key == XK_d)
		camera->transf = ft_matrix_mult(camera->transf,
				ft_translation_matrix(-1, 0, 0));
	else if (key == XK_w)
		camera->transf = ft_matrix_mult(camera->transf,
				ft_translation_matrix(0, 0, -1));
	else if (key == XK_s)
		camera->transf = ft_matrix_mult(camera->transf,
				ft_translation_matrix(0, 0, 1));
	camera->transf = ft_matrix_mult(camera->transf, camera->rotate);
	return (true);
}

static bool	ft_camera_rotate_keys(t_camera *camera, int key)
{
	t_matrix	rotate;

	if (key == XK_Right)
		rotate = ft_rotate_matrix_y(M_PI / 20);
	else if (key == XK_Left)
		rotate = ft_rotate_matrix_y(-M_PI / 20);
	else if (key == XK_Up)
		rotate = ft_rotate_matrix_x(-M_PI / 20);
	else if (key == XK_Down)
		rotate = ft_rotate_matrix_x(M_PI / 20);
	else if (key == XK_q)
		rotate = ft_rotate_matrix_z(-M_PI / 20);
	else if (key == XK_e)
		rotate = ft_rotate_matrix_z(M_PI / 20);
	else
		return (false);
	camera->transf = ft_matrix_mult(camera->transf, rotate);
	camera->rotate = ft_matrix_mult(camera->rotate, rotate);
	camera->inv_rotate = ft_invert_matrix(camera->rotate);
	return (true);
}

static bool	ft_space_c_keys(t_camera *camera, int key)
{
	if (key != XK_space && key != XK_c && key != XK_q && key != XK_e)
		return (false);
	camera->transf = ft_matrix_mult(camera->transf, camera->inv_rotate);
	if (key == XK_space)
		camera->transf = ft_matrix_mult(camera->transf,
				ft_translation_matrix(0, -1, 0));
	else if (key == XK_c)
		camera->transf = ft_matrix_mult(camera->transf,
				ft_translation_matrix(0, 1, 0));
	camera->transf = ft_matrix_mult(camera->transf, camera->rotate);
	return (true);
}

void	ft_transform_camera_key(t_canvas *canvas, int key)
{
	if (ft_camera_wasd_keys(&canvas->camera, key))
		;
	else if (ft_camera_rotate_keys(&canvas->camera, key))
		;
	else if (ft_space_c_keys(&canvas->camera, key))
		;
	else
		return ;
}
