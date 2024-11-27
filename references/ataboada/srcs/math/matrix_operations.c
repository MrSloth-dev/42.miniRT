/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:21:58 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/24 10:51:52 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Multiplies two matrices.
t_matrix	ft_multiply_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	int			k;
	double		s;
	t_matrix	m;

	i = -1;
	m = ft_create_matrix(a.rows, b.cols, NO);
	if (a.cols != b.rows)
		return (ft_create_matrix(0, 0, NO));
	while (++i < a.rows)
	{
		j = -1;
		while (++j < b.cols)
		{
			s = 0;
			k = -1;
			while (++k < a.cols)
				s += a.data[i][k] * b.data[k][j];
			m.data[i][j] = s;
		}
	}
	return (m);
}

// Multiplies a matrix by a tuple.
t_vec3	ft_multiply_matrix_tuple(t_matrix a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.data[0][0] * b.x + a.data[0][1] * b.y + a.data[0][2]
		* b.z + a.data[0][3] * b.w;
	result.y = a.data[1][0] * b.x + a.data[1][1] * b.y + a.data[1][2]
		* b.z + a.data[1][3] * b.w;
	result.z = a.data[2][0] * b.x + a.data[2][1] * b.y + a.data[2][2]
		* b.z + a.data[2][3] * b.w;
	result.w = a.data[3][0] * b.x + a.data[3][1] * b.y + a.data[3][2]
		* b.z + a.data[3][3] * b.w;
	return (result);
}

// Transposes a matrix. This means that the rows become columns and the columns
// become rows.
t_matrix	ft_transpose_matrix(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	m;

	i = -1;
	m = ft_create_matrix(a.cols, a.rows, NO);
	while (++i < a.rows)
	{
		j = -1;
		while (++j < a.cols)
			m.data[j][i] = a.data[i][j];
	}
	return (m);
}

// Returns the inverse of a matrix. The inverse of a matrix is the matrix that
// when multiplied by the original matrix gives the identity matrix.
t_matrix	ft_invert_matrix(t_matrix a)
{
	int			i;
	int			j;
	t_matrix	m;
	double		cofactor;
	double		determinant;

	i = -1;
	m = ft_create_matrix(a.rows, a.cols, NO);
	determinant = ft_get_determinant(a);
	if (determinant == 0)
		return (ft_create_matrix(0, 0, NO));
	while (++i < a.rows)
	{
		j = -1;
		while (++j < a.cols)
		{
			cofactor = ft_get_cofactor(a, i, j);
			m.data[j][i] = cofactor / ft_get_determinant(a);
		}
	}
	return (m);
}
