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

t_ray	ft_ray_for_pixel(t_camera cam, double px, double py)
{
	double		world_x;
	double		world_y;
	t_tuple		pixel;
	t_ray		ret_ray;

	world_x = cam.half_width - ((px + 0.5) * cam.px_size);
	world_y = cam.half_height - ((py + 0.5) * cam.px_size);
	pixel = ft_mult_matrix_tuple(cam.inverted,
			(t_tuple){world_x, world_y, -1, 1});
	ret_ray.pos = ft_mult_matrix_tuple(cam.inverted, (t_tuple){0, 0, 0, 1});
	ret_ray.dir = ft_norm_vector(ft_operator(pixel, '-', ret_ray.pos));
	return (ret_ray);
}
