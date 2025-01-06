/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_005_is_tuples_equal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:12:58 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:13:53 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_tuples_equal(t_tuple tuple1, t_tuple tuple2)
{
	if (tuple1.w != tuple2.w
		|| !ft_is_float_equal(tuple1.x, tuple2.x)
		|| !ft_is_float_equal(tuple1.y, tuple2.y)
		|| !ft_is_float_equal(tuple1.z, tuple2.z))
		return (0);
	return (1);
}
/**/
/*void	test_ft_is_tuples_equal()*/
/*{*/
/*	t_tuple t1, t2;*/
/**/
/*	t1.x = 15, t1.y = 15, t1.z = 15 ,t1.w = 0;*/
/*	t2.x = 15, t2.y = 15, t2.z = 15 ,t2.w = 0;*/
/*	printf("tuple equal %d\n", ft_is_tuples_equal(t1, t2));*/
/*	t1.x = 15, t1.y = 15, t1.z = 15 ,t1.w = 0;*/
/*	t2.x = 15, t2.y = 10, t2.z = 15 ,t2.w = 0;*/
/*	printf("tuple not equal %d\n", ft_is_tuples_equal(t1, t2));*/
/*}*/
