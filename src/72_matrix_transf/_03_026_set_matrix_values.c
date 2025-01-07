/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_026_set_matrix_values.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:27 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_set_matrix_values(t_matrix *m, double values[4][4])
{
	t_iter	h;

	h = ft_iter(0);
	while (h.r < m->rows)
	{
		h.c = 0;
		while (h.c < m->cols)
		{
			m->data[h.r][h.c] = values[h.r][h.c];
			h.c++;
		}
		h.r++;
	}
}
