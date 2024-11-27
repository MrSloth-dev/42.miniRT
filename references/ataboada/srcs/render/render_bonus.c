/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:09 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/30 15:47:07 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_render_threads(t_camera *c, t_world *w)
{
	int			i;
	t_thread	thread[THREADS];
	pthread_t	thread_id[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		thread[i].camera = c;
		thread[i].world = w;
		thread[i].start = i * (c->vsize / THREADS);
		if (i == THREADS - 1)
			thread[i].end = c->vsize;
		else
			thread[i].end = (i + 1) * (c->vsize / THREADS);
		pthread_create(&thread_id[i], NULL, ft_render_bonus, &thread[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(thread_id[i], NULL);
}

void	*ft_render_bonus(void *arg)
{
	int			x;
	int			y;
	t_ray		r;
	t_color		color;
	t_thread	*args;

	args = (t_thread *)arg;
	y = args->start - 1;
	while (++y < args->end)
	{
		x = -1;
		while (++x < args->camera->hsize)
		{
			r = ft_ray_for_pixel(args->camera, x, y);
			color = ft_color_at(args->world, r, 5);
			if ((x > 0 && x < args->camera->hsize)
				&& (y > 0 && y < args->camera->vsize))
			{
				args->dst = args->world->img.addr + (y * args->world
						->img.line_length + x * (args->world->img.bpp / 8));
				*(unsigned int *)args->dst = ft_int_to_rgb(color);
			}
		}
	}
	return (NULL);
}
