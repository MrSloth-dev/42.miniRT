/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_034_determinant.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:43 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_determinant(t_matrix m)
{
	double	det;
	int		c;

	c = -1;
	det = 0;
	ft_assert(m.cols == m.rows, "Matrix not square!");
	if (m.cols == 2)
		det = m.data[0][0] * m.data[1][1] - m.data[1][0] * m.data[0][1];
	else
		while (++c < m.cols)
			det += m.data[0][c] * ft_cofactor(m, 0, c);
	return (det);
}
