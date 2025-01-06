/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_change_object_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:03:30 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:03:35 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	ft_can_change(double actual, double scl)
{
	double	result;

	result = actual + scl;
	if (result > 1 || result < 0)
		return (false);
	return (true);
}

static void	ft_change_color_value(t_canvas *canvas, char color)
{
	double	scl;

	scl = (double)canvas->shift_press / 10;
	if (color == 'r'
		&& ft_can_change(canvas->object_selected->material.color.x, scl))
		canvas->object_selected->material.color.x += scl;
	else if (color == 'g'
		&& ft_can_change(canvas->object_selected->material.color.y, scl))
		canvas->object_selected->material.color.y += scl;
	else if (color == 'b'
		&& ft_can_change(canvas->object_selected->material.color.z, scl))
		canvas->object_selected->material.color.z += scl;
	else if (color == 't')
	{
		ft_change_color_value(canvas, 'r');
		ft_change_color_value(canvas, 'g');
		ft_change_color_value(canvas, 'b');
	}
}

bool	ft_change_object_color(int keysym, t_canvas *canvas)
{
	if (!canvas->object_selected)
		return (false);
	if (keysym == XK_t)
		ft_change_color_value(canvas, 't');
	else if (keysym == XK_r)
		ft_change_color_value(canvas, 'r');
	else if (keysym == XK_g)
		ft_change_color_value(canvas, 'g');
	else if (keysym == XK_b)
		ft_change_color_value(canvas, 'b');
	else
		return (false);
	return (true);
}
