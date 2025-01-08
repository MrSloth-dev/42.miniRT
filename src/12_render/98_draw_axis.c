/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   98_draw_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:45:51 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/08 01:45:51 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_draw_bold_line(t_canvas *c, t_ln_pt data, int color)
{
	ft_draw_line(c, data, color);
	data.actual.x += 1;
	data.actual.y += 1;
	data.next.x += 1;
	data.next.y += 1;
	ft_draw_line(c, data, color);
	data.actual.x += 1;
	data.actual.y += 1;
	data.next.x += 1;
	data.next.y += 1;
	ft_draw_line(c, data, color);
}

void	draw_line_x(t_canvas *c, int color)
{
	t_ln_pt	data;
	int		scale;

	scale = 40;
	data.actual.x = IMG_W - 90;
	data.actual.y = IMG_H - 50;
	data.next.x = data.actual.x + (c->camera.rotate.data[0][0]) * scale;
	data.next.y = data.actual.y + (c->camera.rotate.data[0][1]) * scale;
	data.x_str = 5;
	if (data.next.x < data.actual.x)
		data.x_str = -data.x_str;
	data.y_str = 5;
	if (data.next.y < data.actual.y)
		data.y_str = -data.y_str;
	ft_draw_bold_line(c, data, color);
	c->local_x = data;
}

void	draw_line_y(t_canvas *c, int color)
{
	t_ln_pt	data;
	int		scale;

	scale = 40;
	data.actual.x = IMG_W - 90;
	data.actual.y = IMG_H - 50;
	data.next.x = data.actual.x + c->camera.rotate.data[0][1] * scale;
	data.next.y = data.actual.y - (c->camera.rotate.data[1][1]) * scale;
	data.x_str = 5;
	if (data.next.x < data.actual.x)
		data.x_str = -data.x_str;
	data.y_str = 5;
	if (data.next.y < data.actual.y)
		data.y_str = -data.y_str;
	ft_draw_bold_line(c, data, color);
	c->local_y = data;
}

void	draw_line_z(t_canvas *c, int color)
{
	t_ln_pt	data;
	int		scale;

	scale = 40;
	data.actual.x = IMG_W - 90;
	data.actual.y = IMG_H - 50;
	data.next.x = data.actual.x + c->camera.rotate.data[0][2] * scale + 5;
	data.next.y = data.actual.y + (c->camera.rotate.data[2][1]) * scale - 5;
	data.x_str = 5;
	if (data.next.x < data.actual.x)
		data.x_str = -data.x_str;
	data.y_str = 5;
	if (data.next.y < data.actual.y)
		data.y_str = -data.y_str;
	ft_draw_bold_line(c, data, color);
	c->local_z = data;
}

void	draw_axis(t_canvas *canvas)
{
	draw_line_x(canvas, 0x00CCCC);
	draw_line_y(canvas, 0xCC0000);
	draw_line_z(canvas, 0x00CC00);
}
