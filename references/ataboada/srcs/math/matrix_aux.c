/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:21:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/11 14:21:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Returns a submatrix of a matrix. We remove the row and column of the element.
t_matrix	ft_get_submatrix(t_matrix a, int row, int col)
{
	int			i;
	int			j;
	int			k;
	int			l;
	t_matrix	m;

	i = -1;
	k = 0;
	m = ft_create_matrix(a.rows - 1, a.cols - 1, NO);
	if (a.rows <= 1 || a.cols <= 1 || row >= a.rows || col >= a.cols)
		return (ft_create_matrix(0, 0, NO));
	while (++i < a.rows)
	{
		if (i == row)
			continue ;
		j = -1;
		l = -1;
		while (++j < a.cols)
		{
			if (j != col)
				m.data[k][++l] = a.data[i][j];
		}
		k++;
	}
	return (m);
}

// Returns the minor of a matrix. The minor of an element is the determinant of
// the submatrix that remains after removing the row and column of the element.
double	ft_get_minor(t_matrix a, int row, int col)
{
	t_matrix	submatrix;
	double		determinant;

	submatrix = ft_get_submatrix(a, row, col);
	determinant = ft_get_determinant(submatrix);
	return (determinant);
}

// Returns the cofactor of a matrix. The cofactor of an element is the minor of
// that element multiplied by -1 if the sum of the row and column is odd.
double	ft_get_cofactor(t_matrix a, int row, int col)
{
	double	minor;

	minor = ft_get_minor(a, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	else
		return (-minor);
}

// Returns the determinant of a matrix.
double	ft_get_determinant(t_matrix a)
{
	int		i;
	double	determinant;

	determinant = 0;
	if (a.rows != a.cols)
		return (0);
	else if (a.rows == 2 && a.cols == 2)
		return (a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0]);
	else
	{
		i = -1;
		while (++i < a.cols)
			determinant += a.data[0][i] * ft_get_cofactor(a, 0, i);
	}
	return (determinant);
}
