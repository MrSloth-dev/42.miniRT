/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:39:26 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/03 15:40:26 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_select_obj(int x, int y, t_canvas *canvas)
{
	t_ray		ray;
	t_interlst	*lst;
	t_inter		*hit;

	if (!canvas->objects)
		return ;
	ray.pos = ft_mult_matrix_tuple(canvas->camera.inverted,
			(t_tuple){0, 0, 0, 1});
	ft_ray_for_pixel(canvas->camera, x, y, &ray);
	lst = ft_intersect_world(canvas, ray);
	hit = ft_hit_inter(&lst);
	ft_clear_select(canvas);
	if (hit)
	{
		canvas->object_selected = (t_shapes *)hit->shape;
		hit->shape->selected = true;
	}
	ft_free_objects(lst);
}
