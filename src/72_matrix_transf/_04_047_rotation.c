/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _04_047_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:49 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_rotation_x(t_tuple tuple, double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{1, 0, 0, 0},
	{0, cos(rad), -sin(rad), 0},
	{0, sin(rad), cos(rad), 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}

t_tuple	ft_rotation_y(t_tuple tuple, double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{cos(rad), 0, sin(rad), 0},
	{0, 1, 0, 0},
	{-sin(rad), 0, cos(rad), 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}

t_tuple	ft_rotation_z(t_tuple tuple, double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{cos(rad), -sin(rad), 0, 0},
	{sin(rad), cos(rad), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}

// NOT IMPLEMENTED
/* t_tuple ft_shear(t_tuple tuple, double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{cos(rad), -sin(rad), 0, 0},
	{sin(rad), cos(rad), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
} */
