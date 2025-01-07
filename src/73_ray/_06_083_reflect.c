/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _06_083_reflect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:42:33 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:42:35 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_reflect(t_tuple incoming, t_tuple normal)
{
	double	dot_res;
	t_tuple	res;

	dot_res = ft_dotprod_vector(incoming, normal);
	res = ft_scalar_tuple(normal, 2);
	res = ft_scalar_tuple(res, dot_res);
	res = ft_sub_tuple(incoming, res);
	return (res);
}
