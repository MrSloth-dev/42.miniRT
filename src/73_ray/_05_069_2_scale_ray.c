/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_069_2_scale_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:33 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:42:35 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_scale_ray(t_tuple scaling, t_ray ray)
{
	return ((t_ray){ft_scale(scaling, ray.pos),
		ft_scale(scaling, ray.dir)});
}
