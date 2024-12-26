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

void	ft_custom_pixel_put(t_canvas *canvas, t_iter h, t_tuple color)
{
	h.y_step = 0;
	while (h.y_step < STEP)
	{
		h.x_step = 0;
		while (h.x_step < STEP)
		{
			h.x_step++;
			ft_pixel_put(canvas->img, h.x + h.x_step, h.y + h.y_step,
				ft_get_mlx_color(color));
		}
		h.y_step++;
	}
}

void	ft_render(t_canvas *canvas, t_camera cam)
{
	t_iter	h;
	t_tuple	color;
	t_ray	ray;

	h = ft_iter(0);
	while (h.y < IMG_H)
	{
		h.x = 0;
		while (h.x < IMG_W)
		{
			ray = ft_ray_for_pixel(cam, h.x, h.y);
			color = ft_color_at(canvas, ray);	
			// LINES COMMENTED, test page 105
			// if (h.x == 5 && h.y == 5)
			// {
			// 	printf("\nx = %d, y = %d\n", h.x, h.y);
			// 	ft_print_tuple(color, "color test");
			// }
			ft_custom_pixel_put(canvas, h, color);
			h.x += STEP;
		}
		h.y += STEP;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}
