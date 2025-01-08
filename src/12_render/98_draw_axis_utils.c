/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   98_draw_axis_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:46:00 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/08 01:46:00 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_data_to_draw_line(t_ln_pt *data)
{
	if (!data)
		return ;
	data->x_direction = -1;
	if (data->actual.x < data->next.x)
		data->x_direction = 1;
	data->y_direction = -1;
	if (data->actual.y < data->next.y)
		data->y_direction = 1;
	data->delta_x = abs(data->next.x - data->actual.x);
	data->delta_y = abs(data->next.y - data->actual.y);
	data->err = data->delta_x - data->delta_y;
}

void	ft_draw_line(t_canvas *c, t_ln_pt data, int color)
{
	set_data_to_draw_line(&data);
	while (data.actual.x != data.next.x || data.actual.y != data.next.y)
	{
		data.e2 = 2 * data.err;
		if (data.e2 > -data.delta_y)
		{
			data.err -= data.delta_y;
			data.actual.x += data.x_direction;
		}
		if (data.e2 < data.delta_x)
		{
			data.err += data.delta_x;
			data.actual.y += data.y_direction;
		}
		ft_pixel_put(&c->img, data.actual.x, data.actual.y, color);
	}
}
