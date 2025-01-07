/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_027_are_matrixes_equal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:34 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_are_matrixes_equal(t_matrix a, t_matrix b)
{
	t_iter			h;

	if (a.rows != b.rows || a.cols != b.cols)
		return (0);
	h = ft_iter(-1);
	while (h.r < a.rows)
	{
		h.c = -1;
		while (++h.c < a.cols)
			if (ft_is_float_equal(a.data[h.r][h.c], b.data[h.r][h.c]) == 0)
				return (0);
	}
	return (1);
}
