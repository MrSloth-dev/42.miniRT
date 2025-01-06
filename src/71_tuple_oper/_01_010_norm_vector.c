/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_010_norm_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:13:53 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_norm_vector(t_tuple tuple)
{
	double	magn;

	ft_assert(tuple.w == 0, "Not a Vector");
	magn = ft_magn_tuple(tuple);
	return ((t_tuple){tuple.x / magn,
		tuple.y / magn,
		tuple.z / magn,
		0});
}

/*t_tuple	ft_norm_vector(t_tuple tuple)*/
/*{*/
/*	double	magn;*/
/**/
/*	ft_assert(tuple.w == 0, "Not a Vector");*/
/*	magn = ft_magn_tuple(tuple);*/
/*	return ((t_tuple){tuple.x / magn,*/
/*		tuple.y / magn,*/
/*		tuple.z / magn,*/
/*		tuple.w / magn});*/
/*}*/
