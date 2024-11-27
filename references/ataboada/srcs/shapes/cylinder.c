/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:41:00 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/21 13:45:01 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Calculates whether the specified ray intersects the cylinder.
void	ft_cylinder_intersections(t_intrs **i, t_shapes *s, t_ray r)
{
	t_aux	a;

	ft_cylinder_caps_intersections(i, s, r);
	a.discriminant = ft_get_discriminant(s->type, r, &a);
	if (a.a == 0 || a.discriminant < 0)
		return ;
	a.t0 = (-a.b - sqrt(a.discriminant)) / (2 * a.a);
	a.t1 = (-a.b + sqrt(a.discriminant)) / (2 * a.a);
	if (a.t0 > a.t1)
		ft_swap_double(&a.t0, &a.t1);
	a.y0 = r.origin.y + a.t0 * r.direction.y;
	if (s->cylinder.minimum < a.y0 && a.y0 < s->cylinder.maximum)
		ft_add_sorted_intersection(i, s, a.t0);
	a.y1 = r.origin.y + a.t1 * r.direction.y;
	if (s->cylinder.minimum < a.y1 && a.y1 < s->cylinder.maximum)
		ft_add_sorted_intersection(i, s, a.t1);
}

// Checks if the ray intersects the cylinder's cap.
void	ft_cylinder_caps_intersections(t_intrs **i, t_shapes *s, t_ray r)
{
	double	t;

	if (s->cylinder.closed == false || r.direction.y == 0)
		return ;
	t = (s->cylinder.minimum - r.origin.y) / r.direction.y;
	if (ft_cylinder_check_cap(r, t))
		ft_add_sorted_intersection(i, s, t);
	t = (s->cylinder.maximum - r.origin.y) / r.direction.y;
	if (ft_cylinder_check_cap(r, t))
		ft_add_sorted_intersection(i, s, t);
}

// Checks if the specified point is within the cylinder's caps.
bool	ft_cylinder_check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z <= 1);
}

// Returns the normal vector at the specified point on the cylinder.
t_vec3	ft_cylinder_normal_at(t_shapes *cyl, t_point point)
{
	double	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= cyl->cylinder.maximum - EPSILON)
		return ((t_vec3){0, 1, 0, 0});
	if (dist < 1 && point.y <= cyl->cylinder.minimum + EPSILON)
		return ((t_vec3){0, -1, 0, 0});
	return ((t_vec3){point.x, 0, point.z, 0});
}
