/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _05_062_intersection_sphere.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_intersection_sphere(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;
	t_tuple	sphere_to_ray;
	double	sqrt_discriminant;
	double	two_a;

	sphere_to_ray = ft_sub_tuple(ray.pos, (t_tuple){0, 0, 0, 1});
	h.a = ft_dotprod_vector(ray.dir, ray.dir);
	h.b = 2 * ft_dotprod_vector(ray.dir, sphere_to_ray);
	h.d = ft_dotprod_vector(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (h.b * h.b) - (4 * h.a * h.d);
	if (discriminant < 0)
		return ;
	else
	{
		two_a = 2 * h.a;
		sqrt_discriminant = sqrt(discriminant);
		ft_lstadd_sort_inter(lst, ((-h.b - sqrt_discriminant) / two_a), shap);
		ft_lstadd_sort_inter(lst, ((-h.b + sqrt_discriminant) / two_a), shap);
	}
}
