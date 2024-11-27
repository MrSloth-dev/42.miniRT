/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:25:41 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/23 09:53:27 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Calculates whether the specified ray intersects the cone.
void	ft_cone_intersections(t_intrs **i, t_shapes *s, t_ray r)
{
	t_aux	a;

	ft_cone_caps_intersections(i, s, r);
	a.discriminant = ft_get_discriminant(s->type, r, &a);
	if (a.a == 0)
	{
		if (a.b == 0)
			return ;
		ft_add_sorted_intersection(i, s, -a.c / (2 * a.b));
		return ;
	}
	if (a.discriminant < 0)
		return ;
	a.t0 = (-a.b - sqrt(a.discriminant)) / (2 * a.a);
	a.t1 = (-a.b + sqrt(a.discriminant)) / (2 * a.a);
	if (a.t0 > a.t1)
		ft_swap_double(&a.t0, &a.t1);
	a.y0 = r.origin.y + a.t0 * r.direction.y;
	if (s->cone.minimum < a.y0 && a.y0 < s->cone.maximum)
		ft_add_sorted_intersection(i, s, a.t0);
	a.y1 = r.origin.y + a.t1 * r.direction.y;
	if (s->cone.minimum < a.y1 && a.y1 < s->cone.maximum)
		ft_add_sorted_intersection(i, s, a.t1);
}

// Calculates the intersections of the cone's caps.
void	ft_cone_caps_intersections(t_intrs **i, t_shapes *s, t_ray ray)
{
	double	t;

	if (s->cone.closed == false || ray.direction.y == 0)
		return ;
	t = (s->cone.minimum - ray.origin.y) / ray.direction.y;
	if (ft_cone_check_cap(ray, t, s->cone.minimum))
		ft_add_sorted_intersection(i, s, t);
	t = (s->cone.maximum - ray.origin.y) / ray.direction.y;
	if (ft_cone_check_cap(ray, t, s->cone.maximum))
		ft_add_sorted_intersection(i, s, t);
}

// Checks if the ray intersects the cone's cap.
bool	ft_cone_check_cap(t_ray ray, double t, double range)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z <= range * range);
}

// Returns the normal vector at the specified point of the cone.
t_vec3	ft_cone_normal_at(t_shapes *cone, t_point point)
{
	double	dist;
	double	max_range;
	double	min_range;
	double	y;

	dist = point.x * point.x + point.z * point.z;
	max_range = cone->cone.maximum * cone->cone.maximum;
	if (dist < max_range && point.y >= cone->cone.maximum - EPSILON)
		return ((t_vec3){0, 1, 0, 0});
	min_range = cone->cone.minimum * cone->cone.minimum;
	if (dist < min_range && point.y <= cone->cone.minimum + EPSILON)
		return ((t_vec3){0, -1, 0, 0});
	y = sqrt(dist);
	if (point.y > 0)
		y = -y;
	return ((t_vec3){point.x, y, point.z, 0});
}
