/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_fixed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:27:28 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:27:30 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	ft_init_ambient(int ratio, t_color color)
{
	t_ambient	new;

	new.ratio = ratio;
	new.color = color;
	return (new);
}

t_camera	ft_init_camera(t_tuple coord, t_tuple norm, int fov)
{
	t_camera	new;

	new.coord = coord;
	new.norm = norm;
	new.field_v = fov;
	return (new);
}

t_light	ft_init_light(t_tuple coord, int bright, t_color color)
{
	t_light	new;

	new.coord = coord;
	new.color = ft_scalar_tuple(color, bright);
	return (new);
}
