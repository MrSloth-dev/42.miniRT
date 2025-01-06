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
	if (mousecode == 3)
		canvas->mouse_drag = 1;
	if (mousecode == 1)
		ft_select_obj(x, y, canvas);
	else if (mousecode == 4)
		canvas->camera.field_v -= M_PI / 30;
	else if (mousecode == 5)
		canvas->camera.field_v += M_PI / 30;
	return (0);
}
