/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_000_tuple_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:14:01 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_tuple_init(t_tuple *tuple, t_point coord, int w)
{
	ft_assert((w == 1 || w == 0 || w == 3), "Invalid tuple w!\n");
	tuple->w = w;
	tuple->x = coord.x;
	tuple->y = coord.y;
	tuple->z = coord.z;
}
