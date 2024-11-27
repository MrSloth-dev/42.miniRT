/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:19:55 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/11 17:34:19 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Checks for intersections between the ray and the world. If an intersection is
// found, it is added to the list of intersections.
void	ft_world_intersections(t_intrs **xs, t_world *world, t_ray r)
{
	t_ray		transformed_ray;
	t_list		*objects;
	t_shapes	*s;

	objects = world->objects;
	while (objects)
	{
		s = (t_shapes *)objects->content;
		transformed_ray = ft_transform_ray(r, s->inverted);
		if (s->type == SPHERE)
			ft_sphere_intersections(xs, s, transformed_ray);
		if (s->type == PLANE)
			ft_plane_intersections(xs, s, transformed_ray);
		if (s->type == CYLINDER)
			ft_cylinder_intersections(xs, s, transformed_ray);
		if (s->type == CONE)
			ft_cone_intersections(xs, s, transformed_ray);
		if (s->type == CUBE)
			ft_cube_intersections(xs, s, transformed_ray);
		if (s->type == TRIANGLE)
			ft_triangle_intersections(xs, s, transformed_ray);
		objects = objects->next;
	}
}

// Returns the intersection with the smallest positive t value. The hit is the
// intersection that is closest to the ray origin.
t_intr	*ft_hit(t_intrs *xs)
{
	t_intr	*hit;

	hit = NULL;
	while (xs)
	{
		if (((t_intr *)xs->content)->t - EPSILON > 0)
		{
			if (!hit || ((t_intr *)xs->content)->t < hit->t)
				hit = xs->content;
		}
		xs = xs->next;
	}
	return (hit);
}
