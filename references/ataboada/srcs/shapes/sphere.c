/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:39:59 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/21 13:44:46 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Calculates the discriminant and adds the intersections to the list.
void	ft_sphere_intersections(t_intrs **i, t_shapes *s, t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_vec3	sphere_to_ray;

	sphere_to_ray = ft_op(r.origin, '-', (t_point){0, 0, 0, 1});
	a = ft_dot(r.direction, r.direction);
	b = 2 * ft_dot(r.direction, sphere_to_ray);
	c = ft_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return ;
	else
	{
		ft_add_sorted_intersection(i, s, (-b - sqrt(discriminant)) / (2 * a));
		ft_add_sorted_intersection(i, s, (-b + sqrt(discriminant)) / (2 * a));
	}
}
