/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_039_invert_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:46 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_invert_matrix(t_matrix m)
{
	t_matrix	temp;
	double		det;
	t_iter		h;

	h = ft_iter(-1);
	det = ft_determinant(m);
	ft_assert(det != 0, "Matrix not invertible!\n");
	temp = ft_create_matrix(m.rows, m.cols, 0);
	while (++h.r < m.rows)
	{
		h.c = -1;
		while (++h.c < m.cols)
			temp.data[h.c][h.r] = ft_cofactor(m, h.r, h.c) / det;
	}
	return (temp);
}
