/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _07_100_view_transformation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_view_transformation(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	m;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_tuple		upn;

	m = ft_create_matrix(4, 4, 1);
	upn = ft_norm_vector(up);
	forward = ft_norm_vector(ft_sub_tuple(to, from));
	if (ft_magn_tuple(ft_crossprod_vector(forward, upn)) == 0)
		upn = (t_tuple){0, 0, 1, 0};
	left = ft_crossprod_vector(forward, upn);
	true_up = ft_crossprod_vector(left, forward);
	ft_set_matrix_values(&m, (double [4][4])
	{{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}});
	m = ft_matrix_mult(m, ft_translation_matrix(-from.x, -from.y, -from.z));
	return (m);
}
