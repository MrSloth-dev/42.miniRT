/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_030_matrix_mult.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:40 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_matrix_mult(t_matrix A, t_matrix B)
{
	t_matrix		res;
	t_iter			h;

	h = ft_iter(0);
	ft_assert(A.cols == B.rows, "diff array size");
	res = ft_create_matrix(A.cols, B.rows, 0);
	while (h.c < A.cols)
	{
		h.r = 0;
		while (h.r < B.rows)
		{
			h.k = 0;
			while (h.k < B.rows)
			{
				res.data[h.r][h.c] += A.data[h.r][h.k] * B.data[h.k][h.c];
				h.k++;
			}
			h.r++;
		}
		h.c++;
	}
	return (res);
}
