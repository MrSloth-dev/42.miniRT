/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _04_045_translate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:41:47 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:41:56 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_translate(t_tuple translation, t_tuple to_translate)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4]){
	{1, 0, 0, translation.x},
	{0, 1, 0, translation.y},
	{0, 0, 1, translation.z},
	{0, 0, 0, translation.w}});
	return (ft_mult_matrix_tuple(m, to_translate));
}
	// 1 0 0 2    1     1
	// 0 1 0 3 *  2  =  2
	// 0 0 1 4    3     3
	// 0 0 0 0    0     0
