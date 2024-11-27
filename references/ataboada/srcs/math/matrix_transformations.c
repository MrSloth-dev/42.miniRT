/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:22:02 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/23 19:38:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Creates a matrix with the specified number of rows and columns.
// If identity_matrix is YES, the matrix created will be an identity matrix.
t_matrix	ft_create_matrix(int rows, int cols, bool identity_matrix)
{
	int			i;
	int			j;
	t_matrix	m;

	i = 0;
	m.rows = rows;
	m.cols = cols;
	if (rows > 4 || cols > 4 || (identity_matrix && rows != cols))
		return (ft_create_matrix(0, 0, NO));
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (identity_matrix && i == j)
				m.data[i][j] = 1;
			else
				m.data[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

// Creates a matrix that moves points in space. Having w = 0 makes sure that
// vectors are not affected by translation.
t_matrix	ft_translation_matrix(double x, double y, double z)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	m.data[0][3] = x;
	m.data[1][3] = y;
	m.data[2][3] = z;
	return (m);
}

// Creates a matrix that enlarges or shrinks points in space.
t_matrix	ft_scaling_matrix(double x, double y, double z)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	m.data[0][0] = x;
	m.data[1][1] = y;
	m.data[2][2] = z;
	return (m);
}

// Creates a matrix that rotates points in space. The angle is in radians.
t_matrix	ft_rotation_matrix(char axis, double r)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	if (axis == 'x')
	{
		m.data[1][1] = cos(r);
		m.data[1][2] = -sin(r);
		m.data[2][1] = sin(r);
		m.data[2][2] = cos(r);
	}
	else if (axis == 'y')
	{
		m.data[0][0] = cos(r);
		m.data[0][2] = sin(r);
		m.data[2][0] = -sin(r);
		m.data[2][2] = cos(r);
	}
	else if (axis == 'z')
	{
		m.data[0][0] = cos(r);
		m.data[0][1] = -sin(r);
		m.data[1][0] = sin(r);
		m.data[1][1] = cos(r);
	}
	return (m);
}

t_matrix	ft_view_transform_matrix(t_point from, t_point to, t_vec3 up)
{
	t_vec3		forward;
	t_vec3		upn;
	t_vec3		left;
	t_vec3		true_up;
	t_matrix	orientation;

	upn = ft_normalize(up);
	forward = ft_normalize(ft_op(to, '-', from));
	if (ft_length(ft_cross(forward, upn)) == 0)
		upn = (t_vec3){0, 0, 1, 0};
	left = ft_cross(forward, upn);
	true_up = ft_cross(left, forward);
	orientation = ft_create_matrix(4, 4, NO);
	orientation.data[0][0] = left.x;
	orientation.data[0][1] = left.y;
	orientation.data[0][2] = left.z;
	orientation.data[1][0] = true_up.x;
	orientation.data[1][1] = true_up.y;
	orientation.data[1][2] = true_up.z;
	orientation.data[2][0] = -forward.x;
	orientation.data[2][1] = -forward.y;
	orientation.data[2][2] = -forward.z;
	orientation.data[3][3] = 1;
	return (ft_multiply_matrix(orientation,
			ft_translation_matrix(-from.x, -from.y, -from.z)));
}
