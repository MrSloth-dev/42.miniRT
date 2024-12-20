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
	t_ray		ret_ray;
	double		world_x;
	double		world_y;
	t_tuple		pixel;

	world_x = cam.half_width - ((px + 0.5) * cam.px_size);
	world_y = cam.half_height - ((py + 0.5) * cam.px_size);
	pixel = ft_mult_matrix_tuple(cam.inverted, (t_tuple){world_x, world_y, -1, 1});
	ret_ray.pos = ft_mult_matrix_tuple(cam.inverted, (t_tuple){0, 0, 0, 1});
	ret_ray.dir = ft_norm_vector(ft_operator(pixel, '-', ret_ray.pos));
	return (ret_ray);
}
// #ifndef _07101_RAY_FOR_PIXEL_H
// # define _07101_RAY_FOR_PIXEL_H
//
// # include "minirt.h"
//
// typedef struct s_ray_for_pixel
// {
// 	double		x_offset;
// 	double		y_offset;
// 	double		world_x;
// 	double		world_y;
// 	t_matrix	inverted;
// 	t_tuple		pixel;
// }	t_ray_for_pixel;
//
// #endif
// t_ray	ft_ray_for_pixel(t_camera cam, double px, double py)
// {
// 	t_ray			ret_ray;
// 	t_ray_for_pixel	s;
//
// 	s.x_offset = (px + 0.5) * cam.px_size;
// 	s.y_offset = (py + 0.5) * cam.px_size;
// 	s.world_x = cam.half_width - s.x_offset;
// 	s.world_y = cam.half_height - s.y_offset;
// 	s.inverted = ft_invert_matrix(cam.transf);
// 	s.pixel = ft_mult_matrix_tuple(s.inverted,
// 			(t_tuple){s.world_x, s.world_y, -1, 1});
// 	ret_ray.pos = ft_mult_matrix_tuple(s.inverted, (t_tuple){0, 0, 0, 1});
// 	ret_ray.dir = ft_norm_vector(ft_sub_tuple(s.pixel, ret_ray.pos));
// 	return (ret_ray);
// }
