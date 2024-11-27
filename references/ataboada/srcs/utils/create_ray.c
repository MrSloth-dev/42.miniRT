/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:34:37 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/11 16:34:38 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// This function creates a ray with an origin and a direction.
t_ray	ft_create_ray(t_point origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

// Returns a new ray that is now multiplied by the matrix. Wherever transforma-
// tion you want from the sphere, you can apply the inverse of that to the ray.
t_ray	ft_transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	r;

	r.origin = ft_multiply_matrix_tuple(matrix, ray.origin);
	r.direction = ft_multiply_matrix_tuple(matrix, ray.direction);
	return (r);
}
