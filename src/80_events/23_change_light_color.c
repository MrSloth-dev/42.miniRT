/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_change_light_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:00:04 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:00:05 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_change_light(t_canvas *canvas)
{
	t_color	up_color;
	t_color	up_inten;

	up_color = (t_tuple){0.5, 0.5, 0.5, 3};
	up_inten = (t_tuple){0.006, 0.006, 0.006, 3};
	if (canvas->shift_press == -1)
	{
		up_color = ft_neg_tuple(up_color);
		up_inten = ft_neg_tuple(up_inten);
	}
	canvas->light.color = ft_add_tuple(canvas->light.color, up_color);
	canvas->light.intensity = ft_add_tuple(canvas->light.intensity, up_inten);
}

static void	ft_change_light_value(t_canvas *canvas, char color)
{
	double	intensity_change;

	intensity_change = 0.006 * canvas->shift_press;
	if (color == 'r')
	{
		canvas->light.color.x += canvas->shift_press;
		canvas->light.intensity.x += intensity_change;
	}
	else if (color == 'g')
	{
		canvas->light.color.y += canvas->shift_press;
		canvas->light.intensity.y += intensity_change;
	}
	else if (color == 'b')
	{
		canvas->light.color.z += canvas->shift_press;
		canvas->light.intensity.z += intensity_change;
	}
}

bool	ft_change_light_color(int keysym, t_canvas *canvas)
{
	if (keysym == XK_t)
		ft_change_light(canvas);
	else if (keysym == XK_r)
		ft_change_light_value(canvas, 'r');
	else if (keysym == XK_g)
		ft_change_light_value(canvas, 'g');
	else if (keysym == XK_b)
		ft_change_light_value(canvas, 'b');
	else
		return (false);
	return (true);
}
