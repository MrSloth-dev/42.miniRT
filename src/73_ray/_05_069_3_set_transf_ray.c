/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_069_3_set_transf_ray.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:33 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:42:35 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_set_transf_ray(t_ray ray, t_matrix inverted)
{
	t_ray	temp;

	temp.pos = ft_mult_matrix_tuple(inverted, ray.pos);
	temp.dir = ft_mult_matrix_tuple(inverted, ray.dir);
	return (temp);
}
