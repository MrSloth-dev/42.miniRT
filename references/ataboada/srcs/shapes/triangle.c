/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:26:32 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/25 16:33:26 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Checks if the specified ray intersects the triangle.
void	ft_triangle_intersections(t_intrs **xs, t_shapes *s, t_ray r)
{
	t_vec3	dir_cross_e2;
	t_vec3	p1_to_origin;
	t_vec3	origin_cross_e1;
	t_aux	a;

	dir_cross_e2 = ft_cross(r.direction, s->triangle.e2);
	a.det = ft_dot(s->triangle.e1, dir_cross_e2);
	if (fabs(a.det) < EPSILON)
		return ;
	a.f = 1 / a.det;
	p1_to_origin = ft_op(r.origin, '-', s->triangle.p1);
	a.u = a.f * ft_dot(p1_to_origin, dir_cross_e2);
	if (a.u < 0 || a.u > 1)
		return ;
	origin_cross_e1 = ft_cross(p1_to_origin, s->triangle.e1);
	a.v = a.f * ft_dot(r.direction, origin_cross_e1);
	if (a.v < 0 || (a.u + a.v) > 1)
		return ;
	a.t = a.f * ft_dot(s->triangle.e2, origin_cross_e1);
	return (ft_add_sorted_intersection(xs, s, a.t));
}
