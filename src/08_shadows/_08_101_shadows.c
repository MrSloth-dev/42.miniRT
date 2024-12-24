/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _08_101_shadows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:23:15 by isilva-t          #+#    #+#             */
/*   Updated: 2024/12/23 10:03:06 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_is_shadowed(t_canvas *canvas, t_tuple point)
{
	double		distance;
	t_ray		ray;
	t_interlst	*inter_lst;
	t_inter		*hit;
	t_tuple		v;

	v = ft_sub_tuple(canvas->light.coord, point);
	distance = ft_magn_tuple(v);
	ray.dir = ft_norm_vector(v);
	ray.pos = point;
	inter_lst = ft_inter_world(canvas, ray);
	hit = ft_hit_inter(&inter_lst);
	if (hit && hit->value < distance)
	{
		ft_free_objects((t_objects *)inter_lst);
		return (true);
	}
	ft_free_objects((t_objects *)inter_lst);
	return (false);
}