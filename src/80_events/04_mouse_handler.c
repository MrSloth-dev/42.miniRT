/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:02:02 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:04:46 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_handler(int mousecode, int x, int y, t_canvas *canvas)
{
	int		camera_invert;

	camera_invert = 1;
	if (mousecode == 3)
		canvas->mouse_drag = 1;
	if (mousecode == 1)
		ft_select_obj(x, y, canvas);
	if (mousecode == 4 || mousecode == 5)
		canvas->camera.transf
			= ft_matrix_mult(canvas->camera.transf, canvas->camera.inv_rotate);
	if (mousecode == 4)
		canvas->camera.transf = ft_matrix_mult(canvas->camera.transf,
				ft_translation_matrix(0, 0, -1));
	else if (mousecode == 5)
		canvas->camera.transf = ft_matrix_mult(canvas->camera.transf,
				ft_translation_matrix(0, 0, 1));
	else
		camera_invert = 0;
	if (camera_invert == 1)
	{
		canvas->camera.transf = ft_matrix_mult(canvas->camera.transf,
				canvas->camera.rotate);
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	return (0);
}
