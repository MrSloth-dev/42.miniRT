/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_005_add_tuple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:13:53 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_add_tuple(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	result;

	result.w = tuple1.w + tuple2.w;
	result.x = tuple1.x + tuple2.x;
	result.y = tuple1.y + tuple2.y;
	result.z = tuple1.z + tuple2.z;
	return (result);
}
