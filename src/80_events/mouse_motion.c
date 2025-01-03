/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:40:34 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/03 14:46:40 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	ft_transf_cam_mouse(t_matrix m, int key)
{
	if (key == 1)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(M_PI / 20)));
	else if (key == 2)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(-M_PI / 20)));
	else if (key == 3)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(-M_PI / 20)));
	else if (key == 4)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(M_PI / 20)));
	return (m);
}

static void	ft_drag_mouse(t_canvas *canvas, int condition)
{
	if (canvas->mouse_sum_x > 50)
		canvas->camera.transf = ft_transf_cam_mouse(canvas->camera.transf, 1);
	else if (canvas->mouse_sum_x < -50)
		canvas->camera.transf = ft_transf_cam_mouse(canvas->camera.transf, 2);
	else
		condition = (1 << 3) | condition;
	if (canvas->mouse_sum_y > 50)
		canvas->camera.transf = ft_transf_cam_mouse(canvas->camera.transf, 4);
	else if (canvas->mouse_sum_y < -50)
		canvas->camera.transf = ft_transf_cam_mouse(canvas->camera.transf, 3);
	else
		condition = (1 << 2) | condition;
	if (condition)
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	if (!((condition >> 3) & 1))
	{
		canvas->mouse_sum_x = 0;
		canvas->mouse_prev_x = -1;
	}
	if (!((condition >> 2) & 1))
	{
		canvas->mouse_sum_y = 0;
		canvas->mouse_prev_y = -1;
	}
}

int	mouse_motion(int x, int y, t_canvas *canvas)
{
	(void)y;
	if (canvas->mouse_drag == 1)
	{
		if (canvas->mouse_prev_x == -1)
			canvas->mouse_prev_x = x;
		else
		{
			canvas->mouse_sum_x += canvas->mouse_prev_x - x;
			canvas->mouse_prev_x = x;
		}
		if (canvas->mouse_prev_y == -1)
			canvas->mouse_prev_y = y;
		else
		{
			canvas->mouse_sum_y += canvas->mouse_prev_y - y;
			canvas->mouse_prev_y = y;
		}
		ft_drag_mouse(canvas, 0);
	}
	return (0);
}
