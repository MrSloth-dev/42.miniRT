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

#include "minirt_bonus.h"

//put our colored pixel, to our mlx image.
// we convert a color in 
// tuple format {0 - 1, 0 - 1, 0 - 1} 
// to intteger like 0xFFFFFF
// The STEP is our upscale option, for test with lower resolutions
void	ft_custom_pixel_put_bonus(t_canvas *canvas, t_iter *h, t_tuple color)
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

void	ft_render_painter_aux(t_iter *h, t_thread *t, t_ray *ray)
{
	t_color	color;

	while (h->x < IMG_W)
	{
		ft_ray_for_pixel(t->canvas.camera, h->x, h->y, ray);
		color = ft_color_at(&t->canvas, *ray);
		if (t->canvas.help && h->x < TEXT_W_ZONE
			&& h->y > IMG_H - TEXT_H_ZONE)
			color = ft_add_tuple(color, (t_tuple){-1, -1, -1, 3});
		if ((t->canvas.object_selected || t->canvas.light_selected)
			&& (h->y > IMG_H - 55
			&& (h->x > (IMG_W / 2 - 80) && h->x < (IMG_W / 2 + 80))))
			color = ft_add_tuple(color, (t_tuple){-1, -1, -1, 3});
		ft_custom_pixel_put_bonus(&t->canvas, h, color);
		h->x += t->canvas.step;
	}
}

void	*ft_render_painter(void *canv)
{
	t_iter		h;
	t_ray		ray;
	t_thread	*t;

	t = (t_thread *)canv;
	h = ft_iter(0);
	h.y = t->height_start;
	ray.pos = ft_mult_matrix_tuple(t->canvas.camera.inverted,
			(t_tuple){0, 0, 0, 1});
	while (h.y < t->height_end)
	{
		h.x = 0;
		ft_render_painter_aux(&h, t, &ray);
		h.y += t->canvas.step;
	}
	return (NULL);
}

void	ft_render_bonus(t_canvas *canvas)
{
	int			i;
	t_thread	painter[TR];
	pthread_t	painter_id[TR];

	i = -1;
	while (++i < TR)
	{
		painter[i].canvas = *canvas;
		painter[i].height_start = i * (IMG_H / TR);
		if (i == TR - 1)
			painter[i].height_end = IMG_H;
		else
			painter[i].height_end = (i + 1) * (IMG_H / TR);
		pthread_create(&painter_id[i], NULL, ft_render_painter, &painter[i]);
	}
	i = -1;
	while (++i < TR)
		pthread_join(painter_id[i], NULL);
}
