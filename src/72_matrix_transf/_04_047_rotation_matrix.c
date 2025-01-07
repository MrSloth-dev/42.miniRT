/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _04_047_rotation_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 09:00:20 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_rotate_matrix_x(double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 1);
	m.data[1][1] = cos(rad);
	m.data[1][2] = -sin(rad);
	m.data[2][1] = sin(rad);
	m.data[2][2] = cos(rad);
	return (m);
}

t_matrix	ft_rotate_matrix_y(double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 1);
	m.data[0][0] = cos(rad);
	m.data[0][2] = sin(rad);
	m.data[2][0] = -sin(rad);
	m.data[2][2] = cos(rad);
	return (m);
}

t_matrix	ft_rotate_matrix_z(double rad)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 1);
	m.data[0][0] = cos(rad);
	m.data[0][1] = -sin(rad);
	m.data[1][0] = sin(rad);
	m.data[1][1] = cos(rad);
	return (m);
}
