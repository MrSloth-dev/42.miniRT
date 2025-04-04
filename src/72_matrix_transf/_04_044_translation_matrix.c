/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _04_044_translation_matrix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:46 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_translation_matrix(double x, double y, double z)
{
	t_matrix	temp;

	temp = ft_create_matrix(4, 4, 1);
	temp.data[0][3] = x;
	temp.data[1][3] = y;
	temp.data[2][3] = z;
	return (temp);
}
/*
given  4, 5, 6

on identity matrix
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

then
1 0 4 0
0 1 5 0
0 0 6 0
0 0 0 1

*/
