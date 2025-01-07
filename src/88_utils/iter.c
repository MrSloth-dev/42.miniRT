/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:53 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:43:06 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_iter	ft_iter(int n)
{
	t_iter	h;

	h.r = n;
	h.c = n;
	h.rs = n;
	h.cs = n;
	h.k = n;
	h.x = n;
	h.y = n;
	h.y_step = n;
	h.x_step = n;
	h.a = n;
	h.b = n;
	h.cc = n;
	h.d = n;
	h.inter_one = n;
	h.inter_two = n;
	return (h);
}

//r = row
//c = colum
//rs = row_spared
//cs = col_spared
//k = helper var
