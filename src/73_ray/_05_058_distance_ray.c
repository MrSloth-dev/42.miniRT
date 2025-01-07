/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_058_distance_ray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:33 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:42:35 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_distance_ray(t_ray ray, double time)
{
	return (ft_add_tuple(ray.pos,
			ft_scalar_tuple(ray.dir, time)));
}
