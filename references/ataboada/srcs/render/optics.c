/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:33:15 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/13 14:57:25 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Returns the color of the reflected light.
t_color	ft_reflected_color(t_world *w, t_comps *c, int remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (remaining <= 0)
		return ((t_color){0, 0, 0, 3});
	if (c->object->material.reflective == 0)
		return ((t_color){0, 0, 0, 3});
	reflect_ray = ft_create_ray(c->over_point, c->reflectv);
	color = ft_color_at(w, reflect_ray, remaining - 1);
	return (ft_ops(color, '*', c->object->material.reflective));
}

// Returns the color of the refracted light.
t_color	ft_refracted_color(t_world *w, t_comps *c, int remaining)
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	t_vec3	direction;
	t_ray	refract_ray;

	if (remaining <= 0)
		return ((t_color){0, 0, 0, 3});
	if (c->object->material.transparency == 0)
		return ((t_color){0, 0, 0, 3});
	n_ratio = c->n1 / c->n2;
	cos_i = ft_dot(c->eyev, c->normalv);
	sin2_t = n_ratio * n_ratio * (1 - cos_i * cos_i);
	if (sin2_t > 1)
		return ((t_color){0, 0, 0, 3});
	direction = ft_ops(c->normalv, '*', (n_ratio * cos_i - sqrt(1.0 - sin2_t)));
	direction = ft_op(direction, '-', ft_ops(c->eyev, '*', n_ratio));
	refract_ray = ft_create_ray(c->under_point, direction);
	return (ft_ops(ft_color_at(w, refract_ray, remaining - 1), '*',
			c->object->material.transparency));
}

// Used to calculate the Fresnel effect. Important for determining the amount of
// reflection and refraction at the intersection point.
double	ft_schlick(t_comps *c)
{
	double	cos;
	double	r0;
	double	n;
	double	sin2_t;

	cos = ft_dot(c->eyev, c->normalv);
	if (c->n1 > c->n2)
	{
		n = c->n1 / c->n2;
		sin2_t = n * n * (1 - (cos * cos));
		if (sin2_t > 1)
			return (1.0);
		cos = sqrt(1.0 - sin2_t);
	}
	r0 = pow(((c->n1 - c->n2) / (c->n1 + c->n2)), 2);
	return (r0 + (1 - r0) * pow((1 - cos), 5));
}
