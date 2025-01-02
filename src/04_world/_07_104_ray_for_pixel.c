/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _07101_ray_for_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:21:29 by isilva-t          #+#    #+#             */
/*   Updated: 2024/12/14 12:21:29 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_ray_for_pixel(t_camera cam, double px, double py, t_ray *ray)
{
	double		world_x;
	double		world_y;
	t_tuple		pixel;

	world_x = cam.half_width - ((px + 0.5) * cam.px_size);
	world_y = cam.half_height - ((py + 0.5) * cam.px_size);
	pixel = ft_mult_matrix_tuple(cam.inverted,
			(t_tuple){world_x, world_y, -1, 1});
	ray->dir = ft_norm_vector(ft_operator(pixel, '-', ray->pos));
}
