/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_035_1_submatrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:43 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_submatrix(t_matrix src, int row, int col)
{
	t_matrix	dst;
	t_iter		h;

	h = ft_iter(0);
	ft_assert(!(src.rows <= row || src.cols <= col), "ft_submatrix\n");
	dst = ft_create_matrix(src.rows - 1, src.cols - 1, 0);
	h.rs = -1;
	while (++h.rs < src.rows)
	{
		if (h.rs == row)
			continue ;
		h.cs = -1;
		h.c = 0;
		while (++h.cs < src.cols)
		{
			if (h.cs == col)
				continue ;
			dst.data[h.r][h.c] = src.data[h.rs][h.cs];
			h.c++;
		}
		h.r++;
	}
	return (dst);
}
