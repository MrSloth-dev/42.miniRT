/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_change_light_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:03:09 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:04:46 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_change_light_position(int keysym, t_canvas *canvas)
{
	if (keysym == XK_w)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, 0.2, 0, 0});
	else if (keysym == XK_s)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, -0.2, 0, 0});
	else if (keysym == XK_a)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){-0.2, 0, 0, 0});
	else if (keysym == XK_d)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0.2, 0, 0, 0});
	else if (keysym == XK_q)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, 0, 0.2, 0});
	else if (keysym == XK_e)
		canvas->light.coord = ft_add_tuple(canvas->light.coord,
				(t_tuple){0, 0, -0.2, 0});
	else
		return (false);
	return (true);
}
