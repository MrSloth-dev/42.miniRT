/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_032_transpose_matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:42 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_transpose_matrix(t_matrix src)
{
	double	tmp;
	t_iter	h;

	h = ft_iter(-1);
	while (++h.r < src.rows)
	{
		h.c = h.r;
		while (++h.c < src.cols)
		{
			if (h.c != h.r)
			{
				tmp = src.data[h.r][h.c];
				src.data[h.r][h.c] = src.data[h.c][h.r];
				src.data[h.c][h.r] = tmp;
			}
		}
	}
	return (src);
}
