/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _01_011_crossprod_vector.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_crossprod_vector(t_tuple a, t_tuple b)
{
	ft_assert(a.w == 0, "a is Not a Vector: crossprod");
	ft_assert(b.w == 0, "b is Not a Vector: crossprod");
	return ((t_tuple){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		0});
}
