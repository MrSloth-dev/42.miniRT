/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _03_000_print_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:17 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_matrix(t_matrix m)
{
	t_iter	h;

	h = ft_iter(0);
	printf("\n");
	while (h.r < m.rows)
	{
		h.c = 0;
		while (h.c < m.cols)
		{
			printf("% .5f    ", m.data[h.r][h.c]);
			h.c++;
		}
		printf("\n");
		h.r++;
	}
	printf("\n");
}
