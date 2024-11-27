/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_update_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:04:00 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/07 12:07:29 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_matrix	ft_update_shapes(t_matrix t, int key)
{
	if (key == W)
		return (ft_multiply_matrix(t, ft_rotation_matrix('x', -PI / OBJ_ROT)));
	else if (key == S)
		return (ft_multiply_matrix(t, ft_rotation_matrix('x', PI / OBJ_ROT)));
	else if (key == A)
		return (ft_multiply_matrix(t, ft_rotation_matrix('y', -PI / OBJ_ROT)));
	else if (key == D)
		return (ft_multiply_matrix(t, ft_rotation_matrix('y', PI / OBJ_ROT)));
	else if (key == M)
		return (ft_multiply_matrix(t, ft_rotation_matrix('z', -PI / OBJ_ROT)));
	else if (key == N)
		return (ft_multiply_matrix(t, ft_rotation_matrix('z', PI / OBJ_ROT)));
	else if (key == UP)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, OBJ_TRA, 0)));
	else if (key == DOWN)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, -OBJ_TRA, 0)));
	else if (key == LEFT)
		return (ft_multiply_matrix(t, ft_translation_matrix(-OBJ_TRA, 0, 0)));
	else if (key == RIGHT)
		return (ft_multiply_matrix(t, ft_translation_matrix(OBJ_TRA, 0, 0)));
	else if (key == ALT)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, 0, OBJ_TRA)));
	else if (key == SPACE)
		return (ft_multiply_matrix(t, ft_translation_matrix(0, 0, -OBJ_TRA)));
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

void	ft_update_lights(t_world *w, int key)
{
	t_light	*l;

	l = (t_light *)w->ui.li[w->ui.tflag % w->ui.n_li];
	if (key == UP)
		l->coordinates = ft_op(l->coordinates, '+', (t_point){0, -1, 0, 1});
	else if (key == DOWN)
		l->coordinates = ft_op(l->coordinates, '+', (t_point){0, 1, 0, 1});
	else if (key == LEFT)
		l->coordinates = ft_op(l->coordinates, '+', (t_point){-1, 0, 0, 1});
	else if (key == RIGHT)
		l->coordinates = ft_op(l->coordinates, '+', (t_point){1, 0, 0, 1});
	else if (key == ALT)
		l->coordinates = ft_op(l->coordinates, '+', (t_point){0, 0, 1, 1});
	else if (key == SPACE)
		l->coordinates = ft_op(l->coordinates, '+', (t_point){0, 0, -1, 1});
	else if (key == PLUS)
		l->intensity = ft_ops(l->intensity, '*', 1.3);
	else if (key == MINUS)
		l->intensity = ft_ops(l->intensity, '*', 0.7);
}
