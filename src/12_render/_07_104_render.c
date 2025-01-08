/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _07_104_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:23:14 by isilva-t          #+#    #+#             */
/*   Updated: 2024/12/15 09:29:42 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//put our colored pixel, to our mlx image.
// we convert a color in 
// tuple format {0 - 1, 0 - 1, 0 - 1} 
// to intteger like 0xFFFFFF
// The STEP is our upscale option, for test with lower resolutions
void	ft_custom_pixel_put(t_canvas *canvas, t_iter *h, t_tuple color)
{
	h->y_step = 0;
	while (h->y_step < canvas->step)
	{
		h->x_step = 0;
		while (h->x_step < canvas->step)
		{
			ft_pixel_put(&canvas->img, h->x + h->x_step++, h->y + h->y_step,
				ft_get_mlx_color(color));
		}
		h->y_step++;
	}
}

void	ft_render(t_canvas *canvas)
{
	t_iter	h;
	t_tuple	color;
	t_ray	ray;

	h = ft_iter(0);
	ray.pos = ft_mult_matrix_tuple(canvas->camera.inverted,
			(t_tuple){0, 0, 0, 1});
	while (h.y < IMG_H)
	{
		h.x = 0;
		while (h.x < IMG_W)
		{
			ft_ray_for_pixel(canvas->camera, h.x, h.y, &ray);
			color = ft_color_at(canvas, ray);
			if (canvas->help && h.x < TEXT_W_ZONE && h.y > IMG_H - TEXT_H_ZONE)
				color = ft_add_tuple(color, (t_tuple){-1, -1, -1, 3});
			ft_custom_pixel_put(canvas, &h, color);
			h.x += canvas->step;
		}
		h.y += canvas->step;
	}
	draw_axis(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
}
