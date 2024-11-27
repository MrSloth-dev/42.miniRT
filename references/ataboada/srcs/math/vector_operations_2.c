/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:22:10 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/25 16:29:45 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Calculates the length of a vector (AKA magnitude).
double	ft_length(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

// Normalizes a vector, which means it makes the vector have a length of 1.
t_vec3	ft_normalize(t_vec3 vec)
{
	double	length;

	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		return ((t_vec3){0, 0, 0, vec.w});
	length = ft_length(vec);
	return ((t_vec3){vec.x / length, vec.y / length, vec.z / length, vec.w});
}

// Returns the reflection vector.
t_vec3	ft_reflect(t_vec3 in, t_vec3 normal)
{
	return (ft_op(in, '-', ft_ops(normal, '*', 2 * ft_dot(in, normal))));
}
