/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _07_094_prepare_comp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief this function makes this
 *
 * @param hit intersection
 * @param ray origin ray
 * @return struct that is needed for computation
 */
t_comp	ft_prepare_comp(t_inter *hit, t_ray ray, t_canvas *canvas)
{
	t_comp	temp;

	temp.value = hit->value;
	temp.shape = hit->shape;
	if (temp.shape->selected == true)
		temp.ambient_on_object = (t_color){1.5, 1.5, 1.5, 3};
	else
		temp.ambient_on_object = (t_color){0, 0, 0, 3};
	temp.eyev = ft_neg_tuple(ray.dir);
	temp.point = ft_distance_ray(ray, temp.value);
	temp.normalv = ft_normal_at(temp.shape, temp.point);
	temp.over_point = ft_add_tuple(temp.point,
			ft_scalar_tuple(temp.normalv, ROUND_ERROR));
	if (ft_dotprod_vector(temp.normalv, temp.eyev) < 0)
	{
		temp.inside = true;
		temp.normalv = ft_neg_tuple(temp.normalv);
	}
	else
		temp.inside = false;
	temp.in_shadow = ft_is_shadowed(canvas, temp.over_point);
	return (temp);
}
