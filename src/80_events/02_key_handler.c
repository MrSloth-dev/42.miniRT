/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:58:55 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 09:58:57 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_handler(int keysym, t_canvas *canvas)
{
	mlx_do_key_autorepeaton(canvas->mlx);
	if (keysym == XK_Escape)
		close_handler(canvas);
	else if (keysym == XK_h)
		canvas->help = !canvas->help;
	if (keysym == XK_Shift_L)
		canvas->shift_press = -1;
	else if (ft_make_disco(keysym, canvas))
		;
	else if (ft_light_transform(keysym, canvas))
		;
	else if (ft_change_resolution(keysym, canvas))
		;
	else if (ft_change_obj_properties(keysym, canvas, false))
		;
	else if (ft_camera_transform(keysym, canvas))
		;
	else if (keysym == XK_x)
		ft_clear_select(canvas);
	return (0);
}
