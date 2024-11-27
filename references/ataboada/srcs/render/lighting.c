/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:12 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/07 16:12:31 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Calculates the lighting at a point on a sphere.
t_color	ft_lighting(t_comps *c, t_light *l, bool in_shadow)
{
	t_color	diffuse;
	t_color	specular;
	t_color	ambient;
	t_color	effective_color;
	t_vec3	lightv;

	if (c->object->material.pattern.type != NONE)
		effective_color = ft_pattern_at_shape(c->object->material.pattern,
				c->object, c->over_point);
	else
		effective_color = c->object->material.color;
	effective_color = ft_op(effective_color, '*', l->intensity);
	lightv = ft_normalize(ft_op(l->coordinates, '-', c->over_point));
	ambient = ft_op(effective_color, '*', c->object->material.ambient);
	diffuse = ft_get_diffuse(c, effective_color, lightv);
	specular = ft_get_specular(c, l, lightv);
	if (in_shadow)
		return (ambient);
	return (ft_op(ft_op(ambient, '+', diffuse), '+', specular));
}

// Returns the diffuse color of the object.
t_color	ft_get_diffuse(t_comps *c, t_color effective_color, t_vec3 lightv)
{
	double	light_dot_normal;

	light_dot_normal = ft_dot(lightv, c->normalv);
	if (light_dot_normal < 0)
		return ((t_color){0, 0, 0, 3});
	return (ft_ops(effective_color, '*',
			c->object->material.diffuse * light_dot_normal));
}

// Returns the specular color of the object.
t_color	ft_get_specular(t_comps *c, t_light *l, t_vec3 lightv)
{
	double	light_dot_normal;
	t_vec3	reflectv;
	double	reflect_dot_eye;
	double	fact;

	light_dot_normal = ft_dot(lightv, c->normalv);
	if (light_dot_normal < 0)
		return ((t_color){0, 0, 0, 3});
	reflectv = ft_reflect(ft_ops(lightv, '*', -1), c->normalv);
	reflect_dot_eye = ft_dot(reflectv, c->eyev);
	if (reflect_dot_eye <= 0)
		return ((t_color){0, 0, 0, 3});
	fact = pow(reflect_dot_eye, c->object->material.shininess);
	return (ft_ops(l->intensity, '*', c->object->material.specular * fact));
}
