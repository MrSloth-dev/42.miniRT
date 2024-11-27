/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:22:06 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/11 15:22:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Adds, subtracts or multiplies two vectors.
t_vec3	ft_op(t_vec3 a, char op, t_vec3 b)
{
	double	w;

	w = a.w || b.w;
	if (a.w == 3 && b.w == 3)
		w = 3;
	if (op == '+')
		return ((t_vec3){a.x + b.x, a.y + b.y, a.z + b.z, w});
	if (op == '-')
	{
		if (a.w && b.w && a.w != 3)
			w = 0;
		return ((t_vec3){a.x - b.x, a.y - b.y, a.z - b.z, w});
	}
	if (op == '*')
		return ((t_vec3){a.x * b.x, a.y * b.y, a.z * b.z, w});
	return ((t_vec3){0, 0, 0, 0});
}

// Multiplies or divides a vector by a scalar.
t_vec3	ft_ops(t_vec3 a, char op, double b)
{
	if (op == '*')
		return ((t_vec3){a.x * b, a.y * b, a.z * b, a.w});
	if (op == '/')
		return ((t_vec3){a.x / b, a.y / b, a.z / b, a.w});
	return ((t_vec3){0, 0, 0, 0});
}

// Calculates the dot product of two vectors. This means the sum of the products
// of the corresponding entries of the two sequences of numbers.
double	ft_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// Calculates the perpendicular vector to two vectors.subtr
t_vec3	ft_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x, a.w});
}
