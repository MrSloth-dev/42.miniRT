/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:25:30 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 17:26:35 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_update(void *ptr)
{
	t_world	*w;

	w = (t_world *)ptr;
	if (w->status_key != 0)
	{
		mlx_destroy_image(w->mlx, w->img.img);
		w->img.img = mlx_new_image(w->mlx, w->camera->hsize, w->camera->vsize);
		w->img.addr = mlx_get_data_addr(w->img.img, &w->img.bpp,
				&w->img.line_length, &w->img.endian);
		if (w->status_key != Z)
			w->camera->transform = ft_update_camera(w->camera->transform,
					w->status_key);
		else
			w->camera->transform = w->cam_reset;
		w->camera->inverted = ft_invert_matrix(w->camera->transform);
		ft_render(w->camera, w);
		mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
	}
	return (0);
}

t_matrix	ft_update_camera(t_matrix t, int key)
{
	if (key == W)
		return (ft_multiply_matrix(t, ft_rotation_matrix('x', PI / CAM_ROT)));
	else if (key == S)
		return (ft_multiply_matrix(t, ft_rotation_matrix('x', -PI / CAM_ROT)));
	else if (key == A)
		return (ft_multiply_matrix(t, ft_rotation_matrix('y', PI / CAM_ROT)));
	else if (key == D)
		return (ft_multiply_matrix(t, ft_rotation_matrix('y', -PI / CAM_ROT)));
	else if (key == M)
		return (ft_multiply_matrix(t, ft_rotation_matrix('z', -PI / CAM_ROT)));
	else if (key == N)
		return (ft_multiply_matrix(t, ft_rotation_matrix('z', PI / CAM_ROT)));
	else if (key == UP)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, -CAM_TRA, 0)));
	else if (key == DOWN)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, CAM_TRA, 0)));
	else if (key == LEFT)
		return (ft_multiply_matrix(t, ft_translation_matrix(CAM_TRA, 0, 0)));
	else if (key == RIGHT)
		return (ft_multiply_matrix(t, ft_translation_matrix(-CAM_TRA, 0, 0)));
	else if (key == SPACE)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, 0, -CAM_TRA)));
	else if (key == ALT)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, 0, CAM_TRA)));
	return (ft_update_scaling(t, key));
}

t_matrix	ft_update_scaling(t_matrix t, int key)
{
	if (key == PLUS)
		return (ft_multiply_matrix(t, ft_scaling_matrix(SCA_P, SCA_P, SCA_P)));
	else if (key == MINUS)
		return (ft_multiply_matrix(t, ft_scaling_matrix(SCA_M, SCA_M, SCA_M)));
	return (t);
}
