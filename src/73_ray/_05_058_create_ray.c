/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_058_create_ray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:30 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:42:35 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_create_ray(t_tuple pos, t_tuple dir)
{
	t_ray	ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}
